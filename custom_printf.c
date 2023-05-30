#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *f, ...)
{
	int t = 0, l = 0, i = 0, b = 0;
	va_list a;
	const char *p = f;
	char *buf;
	va_start(a, f);
	while (*p++) l++;
	buf = (char *)malloc((l + 1) * sizeof(char));
	if (!buf) { va_end(a); return (-1); }
	while (f[i])
	{
		if (f[i] != '%')
		{
			buf[b++] = f[i];
			if (b == l) { t += write(STDOUT_FILENO, buf, b); b = 0; }
			t++;
		}
		else
		{
			i++;
			if (f[i] == '%')
			{
				buf[b++] = '%';
				if (b == l) { t += write(STDOUT_FILENO, buf, b); b = 0; }
				t++;
			}
			else if (f[i] == 'c')
			{
				buf[b++] = (char)va_arg(a, int);
				if (b == l) { t += write(STDOUT_FILENO, buf, b); b = 0; }
				t++;
			}
			else if (f[i] == 's')
			{
				const char *s = va_arg(a, const char *);
				int n = 0;
				while (s[n])
				{
					buf[b++] = s[n++];
					if (b == l) { t += write(STDOUT_FILENO, buf, b); b = 0; }
					t++;
				}
			}
		}
		i++;
	}
	if (b) t += write(STDOUT_FILENO, buf, b);
	free(buf);
	va_end(a);
	return (t);
}
