#include <X11/Xlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USAGE "%s [COLOR]\n"

void
error(char *msg)
{
	perror(msg);
	exit(1);
}

int
main(int argc, char **argv)
{
	Display *d;
	Window w;
	XEvent e;
	XColor x;
	Colormap c;
	int s;
	if(argc < 2)
		error("not enough arguments");
	if((d = XOpenDisplay(NULL)) == NULL)
		error("cannot open display");

	s = DefaultScreen(d);
	c = DefaultColormap(d, 0);
	XParseColor(d, c, argv[1], &x);
	XAllocColor(d, c, &x);
	w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 300, 300, 1, BlackPixel(d, s), x.pixel);
	XSelectInput(d, w, ExposureMask | KeyPressMask);
	XMapWindow(d, w);

	for(;;)
	{
		XNextEvent(d, &e);
		if(e.type == KeyPress)
			break;
	}

	return 0;
}
