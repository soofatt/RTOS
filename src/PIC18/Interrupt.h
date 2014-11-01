#ifndef INTERRUPT_H
#define	INTERRUPT_H

#define enableGlobalInterrupt()     (INTCONbits.GIE = 1)
#define disableGlobalInterrupt()    (INTCONbits.GIE = 0)
#define getGlobalInterrupt()        (INTCONbits.GIE)

#define enablePeripheralInterrupt() (INTCONbits.PEIE = 1)
#define disablePeripheralInterrupt()(INTCONbits.PEIE = 0)
#define getPeripheralInterrupt()    (INTCONbits.PEIE)

#endif	/* INTERRUPT_H */

