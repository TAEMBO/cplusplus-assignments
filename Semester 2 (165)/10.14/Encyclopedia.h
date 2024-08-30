#ifndef ENCYCLOPEDIAH
#define ENCYCLOPEDIAH

#include "Book.h"

class Encyclopedia : public Book {
   public:
      void SetEdition(string edition);
      void SetNumPages(int num);
      string GetEdition();
      int GetNumPages();
      void PrintInfo();
   
   private:
      string edition;
      int numPages;
   // TODO: Declare mutator functions -
   //       SetEdition(), SetNumPages()


   // TODO: Declare accessor functions -
   //       GetEdition(), GetNumPages()


   // TODO: Declare a PrintInfo() function that overrides
   //       the PrintInfo() in Book class


   // TODO: Declare private data members

};

#endif