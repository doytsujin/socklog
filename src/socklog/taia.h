/* Public domain. */

#ifndef TAIA_H
#define TAIA_H

#include <skalibs/tai.h>

struct taia {
  tai_t sec;
  uint32_t nano; /* 0...999999999 */
  uint32_t atto; /* 0...999999999 */
} ;

extern void taia_tai(const struct taia *,tai_t *);

extern void taia_now(struct taia *);

extern double taia_approx(const struct taia *);
extern double taia_frac(const struct taia *);

extern void taia_add(struct taia *,const struct taia *,const struct taia *);
extern void taia_addsec(struct taia *,const struct taia *,int);
extern void taia_sub(struct taia *,const struct taia *,const struct taia *);
extern void taia_half(struct taia *,const struct taia *);
extern int taia_less(const struct taia *,const struct taia *);

#define TAIA_PACK 16
extern void taia_pack(char *,const struct taia *);
extern void taia_unpack(const char *,struct taia *);

#define TAIA_FMTFRAC 19
extern unsigned int taia_fmtfrac(char *,const struct taia *);

extern void taia_uint(struct taia *,unsigned int);

#endif
