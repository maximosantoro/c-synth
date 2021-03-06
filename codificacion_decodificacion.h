#include <stdint.h> 
#include <stdio.h>
#include <stdbool.h>


#ifndef CODIFICACION_DECODIFICACION_H
#define CODIFICACION_DECODIFICACION_H

#define MASK_EVENTO 0xf0
#define SHIF_EVENTO 4
#define MASK_VALOR_EN_ALTO_EVENTO 0x80
#define MASK_CANAL 0x0f
#define MAX_BUFFER 1
#define SHIF_UINT8 8
#define HEADER_ID 0x4D546864
#define SIZE 6
#define IDENT_MIDI 0x4D54726B
#define MASK_TIEMPO_SIGUIENTE 0x80
#define SHIF_TIEMPO_SIGUIENTE 7


// ENUMERATIVIVOS NECESARIOS PARA LA DECODIFICACION MIDI
typedef enum {
	PISTA_UNICA,
	MULTIPISTAS_SINCRONICAS,
	MULTIPISTAS_ASINCRONICAS
}formato_t;

typedef enum {
	NOTA_APAGADA,
	NOTA_ENCENDIDA,
	NOTA_DURANTE,
	CAMBIO_DE_CONTROL,
	CAMBIO_DE_PROGRAMA,
	VARIAR_CANAL,
	CAMBIO_DE_PITCH,
	METAEVENTO
}evento_t;

typedef enum{
 	DO,
 	DO_SOTENIDO,
 	RE,
 	RE_SOTENIDO,
 	MI,
 	FA,
 	FA_SOSTENIDO,
 	SOL,
 	SOL_SOTENIDO,
 	LA,
 	LA_SOTENIDO,
 	SI
}nota_t;

//funciones para decodificar midi
bool decodificar_formato(uint16_t valor, formato_t *formato);
bool decodificar_evento(uint8_t valor, evento_t *evento, char *canal, int *longitud);
bool decodificar_nota(uint8_t valor, nota_t *nota, signed char *octava);


#endif