#ifndef INCLUDE_BITFIELD_H_
#define INCLUDE_BITFIELD_H_

#include <iostream>

using elem_type = unsigned char;

class TBitField {
 private:
  size_t  bitLen;                      // ����� �������� ���� (������������ ���������� �������� ��-�� ��-��, �������)
  size_t  memLen;                      // ���-�� ���������, ����������� ��� �������� �������� ����
  elem_type* pMem;                     // ������ ��� ������������� �������� ����

  // ��������� ����
  size_t bitsInElem = std::numeric_limits<elem_type>::digits;
  size_t shiftSize = std::bit_width(bitsInElem - 1);

  // ��������� ������
  size_t GetMemIndex(size_t pos) const noexcept {        // ������ � p��� ��� ���� pos
    return pos >> shiftSize;
  }

  elem_type GetMemMask(size_t pos) const noexcept {      // ������� ����� ��� ���� pos
    return 1 << (pos & (bitsInElem - 1));
  }

 public:
  // ������������ ������������ ����������
  TBitField(size_t _BitLen);                           // ����������� ������������ ����
  TBitField(const TBitField& bf);                      // ����������� �����������
  TBitField(TBitField&& bf) noexcept;                  // move-����������� (����������� ����������� bf � this)
  ~TBitField();                                        // ����������
  TBitField& operator=(const TBitField &bf);
  TBitField& operator=(TBitField &&bf) noexcept;

  size_t size() const noexcept { return bitLen; }      // �������� ����� (�-�� �����)

  bool operator==(const TBitField &bf) const noexcept;
  bool operator!=(const TBitField &bf) const noexcept;

  bool test(size_t i) const;                           // �������� �������� ���� i
  void set(size_t i);                                  // ���������� ��� i
  void reset(size_t i);                                // �������� ��� i

  TBitField  operator|(const TBitField &bf);           // ���
  TBitField  operator&(const TBitField &bf);           // �
  TBitField  operator~(void);                          // ���������
  

  // ����/�����
  friend void swap(TBitField& lhs, TBitField& rhs) noexcept;
  friend std::ostream &operator<<(std::ostream &ostr, const TBitField &bf);
};

#endif  // INCLUDE_BITFIELD_H_