#ifndef INCLUDE_BITFIELD_H_
#define INCLUDE_BITFIELD_H_

#include <iostream>

using elem_type = unsigned char;

class TBitField {
 private:
  size_t  bitLen;                      // длина битового поля (максимальное допустимое значение эл-та мн-ва, универс)
  size_t  memLen;                      // кол-во элементов, необходимое для хранения битового поля
  elem_type* pMem;                     // память для представления битового поля

  // служебные поля
  size_t bitsInElem = std::numeric_limits<elem_type>::digits;
  size_t shiftSize = std::bit_width(bitsInElem - 1);

  // служебные методы
  size_t GetMemIndex(size_t pos) const noexcept {        // индекс в pМем для бита pos
    return pos >> shiftSize;
  }

  elem_type GetMemMask(size_t pos) const noexcept {      // битовая маска для бита pos
    return 1 << (pos & (bitsInElem - 1));
  }

 public:
  // обязательный классический функционал
  TBitField(size_t _BitLen);                           // конструктор специального вида
  TBitField(const TBitField& bf);                      // конструктор копирования
  TBitField(TBitField&& bf) noexcept;                  // move-конструктор (перемещение содержимого bf в this)
  ~TBitField();                                        // деструктор
  TBitField& operator=(const TBitField &bf);
  TBitField& operator=(TBitField &&bf) noexcept;

  size_t size() const noexcept { return bitLen; }      // получить длину (к-во битов)

  bool operator==(const TBitField &bf) const noexcept;
  bool operator!=(const TBitField &bf) const noexcept;

  bool test(size_t i) const;                           // получить значение бита i
  void set(size_t i);                                  // установить бит i
  void reset(size_t i);                                // очистить бит i

  TBitField  operator|(const TBitField &bf);           // или
  TBitField  operator&(const TBitField &bf);           // и
  TBitField  operator~(void);                          // отрицание
  

  // ввод/вывод
  friend void swap(TBitField& lhs, TBitField& rhs) noexcept;
  friend std::ostream &operator<<(std::ostream &ostr, const TBitField &bf);
};

#endif  // INCLUDE_BITFIELD_H_