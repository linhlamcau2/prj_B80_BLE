#include "../../drivers/printf.h"
#include"rd_log.h"
#include "../common/software_uart.h"
#include "../common/string.h"

typedef char* VA_LIST;
#define VA_START(list, param) (list = (VA_LIST)((int)&param + sizeof(param)))
#define VA_ARG(list, type) ((type *)(list += sizeof(type)))[-1]
#define VA_END(list) (list = (VA_LIST)0)

extern void tl_print(char** out, const char *format, VA_LIST list);
char buff_debug[100] = {0};
void rd_log_test(const char *format, ...)
{
	VA_LIST list;

	VA_START(list, format);
	char *buff = buff_debug;
	tl_print(&buff, format, list);
	int len = strlen(buff_debug);
	soft_uart_send((unsigned char *)buff_debug, len);
	VA_END(list);
}


