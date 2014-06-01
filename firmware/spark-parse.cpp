
static const String hex_digits = String("0123456789ABCDEF");
// Turn a hex string into a number.  NB: string has to be in uppercase.
int parse_hex(String s)
{
    int val = 0;
    
    int len = s.length();
    int i;
    for(i=0;i<len;i++) {
        char digit = s.charAt(i);
        int digit_val = hex_digits.indexOf(digit);
        if(digit_val == -1) {
            // Bad digit
            break;
        } else {
            val = (val << 4) + digit_val;
        }
    }
    if(len == 0 || i != len) {
        return -1; // Conversion failure
    } else {
        return val;
    }
}

