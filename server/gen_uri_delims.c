#include <stdio.h>

/* generate a ap_table_t of 256 values, where certain characters are
 * marked "interesting"... for the uri parsing process.
 */

int main(int argc, char *argv[])
{
    int i;
    char *value;

    printf("/* this file is automatically generated by "
	    "gen_uri_delims, do not edit */\n");
    printf("static const unsigned char uri_delims[256] = {");
    for (i = 0; i < 256; ++i) {
	if (i % 20 == 0)
	    printf("\n    ");
	switch (i) {
	case ':': 	value = "T_COLON";	break;
	case '/': 	value = "T_SLASH";	break;
	case '?': 	value = "T_QUESTION";	break;
	case '#': 	value = "T_HASH";	break;
	case '\0': 	value = "T_NUL";	break;
	default:	value = "0";		break;
	}
	printf("%s%c", value, (i < 255) ? ',' : ' ');
    }
    printf("\n};\n");

    return 0;
}
