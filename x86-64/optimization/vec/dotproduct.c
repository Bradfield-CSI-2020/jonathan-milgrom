#include "vec.h"


data_t dotproduct(vec_ptr u, vec_ptr v) {
   data_t sum = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
   int l = vec_length(u);
   long i;

   for (i = 0; i + 3 < l; i+=4) { // we can assume both vectors are same length
      sum1 += u->data[i] * v->data[i];
      sum2 += u->data[i + 1] * v->data[i + 1];
      sum3 += u->data[i + 2] * v->data[i + 2];
      sum4 += u->data[i + 3] * v->data[i + 3];
   }

   sum = sum1 + sum2 + sum3 + sum4;

   for (; i < l; i++) {
      sum += u->data[i] * v->data[i];
   }

   return sum;
}
