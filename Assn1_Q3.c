/* 
 * Filename: Assn1_Q3.c
 *
 * Description: CMPT-201 Assignment 1, Question 3
 *
 * Authors: Our textbook + AL + Fardin Abdulla
 * Student number: 301540223
 * Date: May 2025
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 typedef unsigned char *byte_pointer;
 
 // Question 3 a.
 void show_bytes(byte_pointer start, size_t len) {
   size_t i;
   for (i = 0; i < len; i++)
     printf("%p 0x%.2x\n", (start + i), *(start + i));
   printf("\n");
   return;	
 }
 
 // Question 3 b.
 // The target machine is little-endian. For example, when show_bytes is called with an integer 0x12345678,
 // output shows the least significant byte (0x78) at the lowest memory address (like, 0x7ffe5fb887cc),
 // followed by 0x56, 0x34, and 0x12 at increasing address. In a big-endian system, 
 // the most significant byte (0x12) would appear at the lowest address, which we didnt see here.
 
 
 // Question 3 c.
 void show_bytes_2(byte_pointer start, size_t len) {
   size_t i;
   for (i = 0; i < len; i++)
     printf("%p 0x%.2x\n", (start + i), *(start + i));  
   printf("\n");
   return;    
 }
 
 // Question 3 d.
 void show_bits(int decimal) {
   int i;
   for (i = sizeof(int) * 8 - 1; i >= 0; i--) {
     int bit = (decimal >> i) & 1;
     printf("%d", bit);
   }
   printf("\n");
   return; 
 }  
 
 // Question 3 e.
 int mask_LSbits(int n) {
   if (n <= 0) return 0;
   if (n >= sizeof(int) * 8) return ~0;
   return (1 << n) - 1;
 }
 
 void show_int(int x) {
   printf("\nival = %d\n", x); 
   show_bytes((byte_pointer) &x, sizeof(int)); 
   show_bytes_2((byte_pointer) &x, sizeof(int)); 
   return;  
 }
 
 void show_float(float x) {
   printf("fval = %f\n", x);   
   show_bytes((byte_pointer) &x, sizeof(float));
   show_bytes_2((byte_pointer) &x, sizeof(float)); 
   return;  
 }
 
 void show_pointer(void *x) {
   printf("pval = %p\n", x); 
   show_bytes((byte_pointer) &x, sizeof(void *));
   show_bytes_2((byte_pointer) &x, sizeof(void *));
   return;  
 }