/*
    ==================================================
    Workshop #6 (Part-1):
    ==================================================
    Name   : Sangwoo Shin
    ID     : 119294213
    Email  : sshin36@myseneca,ca
    Section: NCC
    Date   : Mar 02, 2022
*/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
   private:
      char* m_name{};
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];
      bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
      void setEmpty();
      void allocateAndCopy(const char* name);
      void extractChar(std::istream& istr, char ch) const;
      std::ostream& printIDInfo(std::ostream& ostr) const;
      void set(const char* name, long long number, const char vCode[], const char sNumber[]);
   public:
       HealthCard(const char* name = nullptr, long long number = 0, const char code[] = {}, const char sNumber[] = {});
       HealthCard& operator=(const HealthCard& hc);
       HealthCard(const HealthCard& hc);       
       operator bool() const;
       ~HealthCard();
       std::ostream& print(std::ostream& ostr, bool toFile = true) const;
       std::istream& read(std::istream& istr);
   };
   std::ostream& operator<< (std::ostream& ostr, const HealthCard& hc);
   std::istream& operator>> (std::istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H


