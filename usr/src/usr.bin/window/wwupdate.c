#ifndef lint
static	char *sccsid = "@(#)wwupdate.c	3.5 83/08/16";
#endif

#include "ww.h"
#include "tt.h"

wwupdate()
{
	int i;
	register j;
	int c, x;
	register union ww_char *ns, *os;
	register char *p, *q;
	char m;
	char *touched;
	register didit;
	char buf[512];			/* > wwncol */

	wwnupdate++;
	(*tt.tt_setinsert)(0);
	for (i = 0, touched = wwtouched; i < wwnrow; i++, touched++) {
		if (!*touched)
			continue;
		wwntouched++;
		*touched = 0;

		ns = wwns[i];
		os = wwos[i];
		didit = 0;
		for (j = 0; j < wwncol;) {
			for (; j++ < wwncol && ns++->c_w == os++->c_w;)
				;
			if (j > wwncol)
				break;
			p = buf;
			m = ns[-1].c_m;
			c = j - 1;
			os[-1] = ns[-1];
			*p++ = ns[-1].c_c;
			x = 5;
			q = p;
			while (j < wwncol && ns->c_m == m) {
				*p++ = ns->c_c;
				if (ns->c_w == os->c_w) {
					if (--x <= 0)
						break;
					os++;
					ns++;
				} else {
					x = 5;
					q = p;
					*os++ = *ns++;
				}
				j++;
			}
			(*tt.tt_move)(i, c);
			(*tt.tt_setmodes)(m);
			(*tt.tt_write)(buf, q - 1);
			didit++;
		}
		if (!didit)
			wwnmiss++;
	}
}
