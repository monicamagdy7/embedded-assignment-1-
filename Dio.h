#ifndef DIO_H_
#define DIO_H_

void DIO_vidSetPortDirection( u8 port, u8 dir );
void DIO_vidSetPortValue( u8 port, u8 val );
u8 DIO_u8ReadPortValue( u8 port );
void DIO_vidSetPinDir( u8 port, u8 pin, u8 dir );
void DIO_vidSetPinVal( u8 port, u8 pin, u8 val );

#endif /* DIO_H_ */
//macros.h
