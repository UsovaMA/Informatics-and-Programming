from sqlite3.dbapi2 import version
import discord
from discord.ext import commands
import random
import sqlite3
import configparser
import logging
import datetime
from datetime import date
import uuid
import os.path


conn = sqlite3.connect("users.db")
cursor = conn.cursor()


current_date_time = datetime.datetime.now()
current_time = current_date_time.time()


logging.basicConfig(filename=f"logs/{str(date.today())}.log", level=logging.INFO)


config = configparser.ConfigParser()
config.read('config.conf')


version = config["BOT"]["version"]


vhod = int(input('Какой токен грузить? 1 - Renky, 2 - Blitzo: '))


if (vhod == 1):
    token = config['BOT']['tokenRenky']
    bot = commands.Bot(command_prefix=config['BOT']['prefixRenky'], activity=discord.Game(version))
else:
    token = config['BOT']['tokenBlitzo']
    bot = commands.Bot(command_prefix=config['BOT']['prefixBlitzo'], activity=discord.Game(version))


bot.remove_command('help')


@bot.event
async def on_ready():
    logging.info(f' Начало работы: {datetime.datetime.now()}' + ' | Авторизован как: {0.user}'.format(bot))
    print('Оно дышит!')
    pass


@bot.event
async def on_message(message):
    global messag
    messag = message.content
    await bot.process_commands(message)
    if str(message.author) == "Renny#0790":
        return
    logging.info(f'"{message.author}": {message.content} | {datetime.datetime.now()} \n')
    pass


@bot.command(pass_context=True, name='ping', description='Покажет пинг.')
async def ping(ctx):
    embed = discord.Embed(title="Понг!", description=f"Пинг: {round(bot.latency * 1000)} ms\nВес базы данных {os.path.getsize('users.db') / 1024 / 1024} мб.")
    embed.set_thumbnail(url="https://media1.tenor.com/images/7338662ed35146376e196fbb5655bd25/tenor.gif?itemid=16365441")
    embed.set_footer(text="Core version: " + version)
    await ctx.send(embed=embed)
    pass


@bot.command(name='commands', description='Выводит список команд.')
async def help_com(ctx):
    comm_list = ['Используйте префикс `r!`\n']
    for command in bot.commands:
        if not command.hidden:
            comm_list.append(f'`{command}` — {command.description}\n')
    embed = discord.Embed(title=f'Список команд для {bot.user.name}:', description=''.join(comm_list),
                          color=ctx.author.colour)
    embed.set_footer(text=f'Вызвано пользователем {ctx.author}' + f" | Пинг: {round(bot.latency * 1000)} ms",
                     icon_url='')
    a = random.randint(0, 3)
    await ctx.send(embed=embed)
    pass


@bot.command(name='reg', description='Регистрация в базе данных. [Имя] [Фамилия] [Возраст] [Пол] [краткое описание. (Внешность, вид, рост и так далее)]')
async def registration(ctx, name, surname, age, gender, *, bio):
    pers_id = safeId = uuid.uuid4()
    cursor.execute(f"""CREATE TABLE {name}_{surname}
                  (Name text, Surname text, Age text,
                   Gender text, Bio text, user text, lvl integer, perks integer, lvl_up integer, perception integer, dexterity integer, phys integer, mag integer, Id text)
               """)
    cursor.execute(f"""INSERT INTO {name}_{surname}
                  VALUES ('{name}', '{surname}', '{age}',
                  '{gender}', '{bio}', '{ctx.author}', 1, 5, 0, 0, 0, 0, 0, '{pers_id}')"""
               )
    conn.commit()
    embed=discord.Embed(title="Успешно!", description=f"Персонаж `{name} {surname}` был внесён в базу данных!\n```\nВозраст: {age} \nПол: {gender}\n```")
    embed.set_footer(text=f"id персонажа: {pers_id}")
    await ctx.send(embed=embed)
    pass


@bot.command(name='del', description='Удаляет персонажа из базы данных. [Имя персонажа] [Фамилия]')
@commands.has_permissions(administrator = True)
async def delet(ctx, name, surname):
    own_give = f"SELECT user FROM {name}_{surname}"
    cursor.execute(own_give)
    info = cursor.fetchall()
    for row in info:
            owner = row[0]
    if (ctx.author == str(owner)):
        delete = f"DROP TABLE {name}_{surname}"
        cursor.execute(delete)
        conn.commit()
        embed=discord.Embed(title="Успешно!", description=f"Персонаж `{name} {surname}` был удалён из базы данных!")
        embed.set_footer(text=f"Вы убийца...")
        await ctx.send(embed=embed)
    else:
        logging.warning(f' У пользователя "{ctx.author}" было недостаточно прав. "{messag}". {datetime.datetime.now()} \n')
        embed=discord.Embed(title="Ошибка!", description=f"```У вас недостаточно прав...```")
        embed.set_footer(text="You are missing permission(s) to run this command.")
        await ctx.send(embed=embed)
    pass


@bot.command(name='info', description='Выводит сведения о персонаже. [Имя] [Фамилия]')
async def inform(ctx, name, surname):
    info = f"SELECT * FROM {name}_{surname}"
    cursor.execute(info)
    info = cursor.fetchall()
    for row in info:
            age = row[2]
            gender = row[3]
            bio = row[4]
            owner = row[5]
            lvl = row[6]
            perks = row[7]
            lvl_up = row[8]
            Id = row[13]
    level = float(config["GAME"]["level"]) * float(lvl / 2)
    embed=discord.Embed(title=f"Информация о персонаже {name} {surname}", description=f"Владелец `{owner}`")
    embed.add_field(name="Уровень персонажа", value=f"{lvl} | ({perks}) - очков доступно", inline=True)
    embed.add_field(name="Очков опыта", value=f"{lvl_up}/{level}", inline=True)
    embed.add_field(name="Описание:", value=f"Возраст - `{age}`\nПол - `{gender}`", inline=False)
    embed.add_field(name="Биография:", value=f"```{bio}```", inline=False)
    embed.set_footer(text=f'ID: {Id}')
    await ctx.send(embed=embed)
    pass


@bot.command(name='math', description='Выполнит математические действия.')
async def math(ctx, *, arg):
    result = str(exec(arg))
    embed = discord.Embed(title="Результат операции " + "`" + arg + "`" + ":", description="```" + result + "```")
    embed.set_footer(text=f"Пинг: {round(bot.latency * 1000)} ms")
    await ctx.send(embed=embed)
    pass


@bot.command(name='+', description='Добавляет опыт персонажу. [Имя персонажа] [Фамилия] [Опыт (целое число)]')
@commands.has_permissions(administrator = True)
async def add(ctx, name, surname, count: int):
    add_lvl = f"SELECT lvl_up FROM {name}_{surname}"
    cursor.execute(add_lvl)
    info = cursor.fetchall()
    for row in info:
            lvl_up = row[0]
    
    add_lvl = f"SELECT lvl FROM {name}_{surname}"
    cursor.execute(add_lvl)
    info = cursor.fetchall()
    for row in info:
            lvl = row[0]
    
    add_lvl = f"SELECT perks FROM {name}_{surname}"
    cursor.execute(add_lvl)
    info = cursor.fetchall()
    for row in info:
            perks = row[0]

    embed=discord.Embed(title=f"Вы выдали персонажу {name} {surname} опыт: {count}", description=f"")
    lvl_up = lvl_up + count
    lvl_up2 = float(config["GAME"]["level"]) * float(lvl / 2)

    if (lvl_up >= lvl_up2):
        lvl = lvl + 1
        lvl_up = lvl_up - lvl_up2
        up = f"UPDATE {name}_{surname} SET lvl={lvl}"
        cursor.execute(up)
        conn.commit()
        up = f"UPDATE {name}_{surname} SET lvl_up={lvl_up}"
        cursor.execute(up)
        conn.commit()
        up = f"UPDATE {name}_{surname} SET perks={lvl_up}"
        cursor.execute(up)
        conn.commit()
        perks = perks + 2
        up = f"UPDATE {name}_{surname} SET perks={perks}"
        cursor.execute(up)
        conn.commit()
        lvl_up2 = float(config["GAME"]["level"]) * float(lvl / 2)
        embed.add_field(name=f'Новый уровень: `{lvl}`. Вы волучили очки навыков: `2`', value=f'Опыт: `{lvl_up} из {lvl_up2}` | Доступные очки навыков: `{perks}`', inline=False)
        await ctx.send(embed=embed)
        return
    up = f"UPDATE {name}_{surname} SET lvl_up={lvl_up}"
    cursor.execute(up)
    conn.commit()
    embed.add_field(name=f'Опыт: `{lvl_up} из {lvl_up2}`', value=f'До следующего уровня `{lvl_up2 - lvl_up}`', inline=False)
    await ctx.send(embed=embed)
    pass


@bot.command(name='perks', description='Выводит очки умений персонажа. [имя] [фамилия]')
async def perk(ctx, name, surname):
    perks_give = f"SELECT perks FROM `{name}_{surname}`"
    cursor.execute(perks_give)
    info = cursor.fetchall()
    for row in info:
            perks = row[0]
    
    perception_give = f"SELECT perception FROM {name}_{surname}"
    cursor.execute(perception_give)
    info = cursor.fetchall()
    for row in info:
            perception = row[0]
    
    dexterity_give = f"SELECT dexterity FROM {name}_{surname}"
    cursor.execute(dexterity_give)
    info = cursor.fetchall()
    for row in info:
            dexterity = row[0]
    
    phys_give = f"SELECT phys FROM {name}_{surname}"
    cursor.execute(phys_give)
    info = cursor.fetchall()
    for row in info:
            phys = row[0]
    
    mag_give = f"SELECT mag FROM {name}_{surname}"
    cursor.execute(mag_give)
    info = cursor.fetchall()
    for row in info:
            mag = row[0]

    lvl_give = f"SELECT lvl FROM {name}_{surname}"
    cursor.execute(lvl_give)
    info = cursor.fetchall()
    for row in info:
            lvl = row[0]
    

    embed=discord.Embed(title=f"Очки навыков для {name} {surname}", description=f"Доступные очки навыков: `{perks}`")
    embed.add_field(name=f'Статы:', value=f'1. Концентрация: `{perception}`\n2. Ловкость: `{dexterity}`\n3. Физический потенциал: `{phys}`\n4. Магический потенциал: `{mag}`', inline=False)
    embed.set_footer(text=f"Уровень персонажа: {lvl}")
    await ctx.send(embed=embed)
    pass


@bot.command(name='add_perk', description='Распределение очков навыков. [имя] [фамилия] [колличество очков] [Навык (1 - 4)]')
async def perk_add(ctx, name, surname, perks_dis: int, category: int):
    own_give = f"SELECT user FROM {name}_{surname}"
    cursor.execute(own_give)
    info = cursor.fetchall()
    for row in info:
            owner = row[0]
    
    if (str(ctx.author) == str(owner)):
        perk_give = f"SELECT perks FROM {name}_{surname}"
        cursor.execute(perk_give)
        info = cursor.fetchall()
        for row in info:
            perks = row[0]

        perks_add = perks - perks_dis

        if (perks_add < 0):
            embed=discord.Embed(title=f"Ошибка!", description=f"```Недостаточно очков навыков!```")
            embed.set_footer(text=f"У вас сейчас {perks} очков навыков.")
            await ctx.send(embed=embed)
            return
        
        up = f"UPDATE {name}_{surname} SET perks={perks_add}"
        cursor.execute(up)
        conn.commit()
        categorys = ['0', 'perception', 'dexterity', 'phys', 'mag']
        
        stat_give = f"SELECT {categorys[category]} FROM {name}_{surname}"
        cursor.execute(stat_give)
        info = cursor.fetchall()
        for row in info:
            stat = row[0]
        stat = stat + perks_dis
        up = f"UPDATE {name}_{surname} SET {categorys[category]}={stat}"
        cursor.execute(up)
        conn.commit()
        embed=discord.Embed(title=f"Распределение очков навыков", description=f"Вы вложили `{perks_dis}` в `{categorys[category]}`")
        embed.set_footer(text=f"Осталось очков: {perks_add}")
        await ctx.send(embed=embed)

    else:
        logging.warning(f' У пользователя "{ctx.author}" было недостаточно прав. "{messag}". {datetime.datetime.now()} \n')
        embed=discord.Embed(title="Ошибка!", description=f"```У вас недостаточно прав...```")
        embed.set_footer(text="You are missing permission(s) to run this command.")
        await ctx.send(embed=embed)
    pass


@bot.command(name='r', description='Кидает кубик. [Имя] [Фамилия] [до какого числа] [mag/phys/spd/def]')
async def roll(ctx, name, surname, num: int, tip):
    if (tip == 'mag'):
        tip = 'mag'
    if (tip == 'phys'):
        tip = 'phys'
    if (tip == 'spd'):
        tip = 'dexterity'
    if (tip == 'def'):
        tip = 'perception'
    perks_give = f"SELECT {tip} FROM `{name}_{surname}`"
    cursor.execute(perks_give)
    info = cursor.fetchall()
    for row in info:
            perks = row[0]
    rand = random.randint(1, num)
    rand2 = rand + perks
    result = f"Итог: `{rand2}`\nБонус: `{rand} + {perks}`"
    await ctx.send(result)
    pass


@bot.event
async def on_command_error(ctx, error):

    if isinstance(error, commands.MissingRequiredArgument):
        logging.info(f' Пользователь "{ctx.author}" ввёл команду неправильно. "{messag}". {datetime.datetime.now()} \n    {error}\n')
        embed=discord.Embed(title="Ошибка!", description="```не соотвествует форме. Попробуйте ещё раз...```")
        embed.set_footer(text=error)

    if isinstance(error, commands.errors.CommandInvokeError):
        logging.warning(f' Пользователь "{ctx.author}" передал неверные аргументы. "{messag}". {datetime.datetime.now()} \n    {error}\n')
        embed=discord.Embed(title="Ошибка!", description=f"```Переданы неверные/повторные аргументы...```")
        embed.set_footer(text=error)
    
    if isinstance(error, commands.errors.MissingPermissions):
        logging.warning(f' У пользователя "{ctx.author}" было недостаточно прав. "{messag}". {datetime.datetime.now()} \n    {error}\n')
        embed=discord.Embed(title="Ошибка!", description=f"```У вас недостаточно прав...```")
        embed.set_footer(text=error)
    await ctx.send(embed=embed)
    pass


bot.run(token)