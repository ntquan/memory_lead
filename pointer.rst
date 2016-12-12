# memory_lead
Some codes make the lead memory
Number 01:
  ###########################
  int compute ( char *dip, int dip_len, u16 dport )
  {
      unsigned char buf[dip_len+2];
      memcpy ( &buf+0, dip,  dip_len);
      memcpy ( &buf+dip_len, &dport,2);
      return <something>;
  }
  ###########################
  The issue is line 8. Because "&buf+dip_lex" is equivalent with "&buf + dip_len * sizeof(buf)"
  For example:
    int main()
    {
        int c;
        char abc[3];
        printf("%p\n", (void*)abc); /*0x7ffd60af1400*/
        printf("%p\n", (void*)&abc); /*0x7ffd60af1400*/
        printf("%p\n", (void*)(&abc+1)); /*0x7ffd60af143*/
        printf("%p\n", (void*)(&abc+2)); /*0x7ffd60af1406*/
        printf("%p\n", (void*)(&abc+3)); /*0x7ffd60af1409*/
        printf("%d\n", c); 
        return 1;
    }
  The output:
    0x7ffd60af1400
    0x7ffd60af1400
    0x7ffd60af1403 <-- 0 + 3x1
    0x7ffd60af1406 <-- 0 + 3x2
    0x7ffd60af1409 <-- 0 + 3x3
  ################### How to fix ##############
  int compute ( char *dip, int dip_len, u16 dport )
  {
      unsigned char buf[dip_len+2];
      memcpy ( buf, dip,  dip_len);
      memcpy ( buf+dip_len, &dport,2);
      return <something>;
  }
  or
  int compute ( char *dip, int dip_len, u16 dport )
  {
      unsigned char buf[dip_len+2];
      memcpy ( &buf[0], dip,  dip_len);
      memcpy ( &buf[dip_len], &dport,2);
      return <something>;
  }
