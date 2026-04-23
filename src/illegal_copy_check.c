void illegal_copy_check(void) {
    unsigned char *flag1  = (unsigned char *)0x801FFFF0;
    unsigned char *flag2  = (unsigned char *)0x801FFFF4;
    unsigned char *output = (unsigned char *)0x801FFFF8;

    if (*flag1 == 0) {
        *output = 0xFF;
        return;
    }

    if (*flag2 == 0) {
        *output = 0xFF;
        return;
    }

    *output = 0;
}
