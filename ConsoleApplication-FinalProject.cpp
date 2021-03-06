// ConsoleApplication-FinalProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "aes.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#define PAGELIMIT 80

#ifdef _WIN32
#define WINPAUSE system("pause")
#endif

using namespace std;
// prints string as hex
static void phex(uint8_t* str)
{

#ifdef AES128
	uint8_t len = 16;
#elif defined(AES192)
	uint8_t len = 24;
#elif defined(AES256)
	uint8_t len = 32;
#endif

	unsigned char i;
	for (i = 0; i < len; ++i)
		printf("%.2x", str[i]);
	printf("\n");
}

void buildAString(unsigned char * str)
{
	str[0] = 'L';
	str[1] = 'O';
	str[2] = 'P';
	str[3] = 'E';
	str[4] = 'R';
	str[5] = 'S';
	str[6] = '\0';
}

void Encryption()
{
	char input[16];
	printf("\nEnter a password: ");
	scanf("%s", &input);


	// Encryption done here!

	uint8_t i;

	// 128 bit key
	uint8_t key[16] = { (uint8_t)0x2b, (uint8_t)0x7e, (uint8_t)0x15, (uint8_t)0x16, (uint8_t)0x28, (uint8_t)0xae, (uint8_t)0xd2, (uint8_t)0xa6, (uint8_t)0xab, (uint8_t)0xf7, (uint8_t)0x15, (uint8_t)0x88, (uint8_t)0x09, (uint8_t)0xcf, (uint8_t)0x4f, (uint8_t)0x3c };

	//hex value buildAString function 540bit

	uint8_t in[80] = {
		(uint8_t)0x55, (uint8_t)0x89, (uint8_t)0xe5, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x4c, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x01, (uint8_t)0xc6,
		(uint8_t)0x00, (uint8_t)0x4f, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x02, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x50, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0,
		(uint8_t)0x03, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x45, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x04, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x52, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08,
		(uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x05, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x53, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x06, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x90,
		(uint8_t)0x5d, (uint8_t)0xc3, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14 };
	//Plain text
	uint8_t out[80] = {
		(uint8_t)0x55, (uint8_t)0x89, (uint8_t)0xe5, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x4c, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x01, (uint8_t)0xc6,
		(uint8_t)0x00, (uint8_t)0x4f, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x02, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x50, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0,
		(uint8_t)0x03, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x45, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x04, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x52, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08,
		(uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x05, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x53, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x06, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x90,
		(uint8_t)0x5d, (uint8_t)0xc3, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14 };

	//Xored key with password 

	int len = strlen(input);
	uint8_t* newKey = (uint8_t *)malloc(sizeof(uint8_t *) *len);
	//newKey bit size is the password bit size
	for (i = (uint8_t)0; i < (uint8_t)len; ++i)
	{
		newKey[i] = (uint8_t)(key[i] ^ input[i]);
	}

	// print text to encrypt, key and IV
	printf("plain text:\n");
	for (i = (uint8_t)0; i < (uint8_t)5; ++i)
	{
		phex(in + (i * (uint8_t)16));
	}
	printf("\n");

	printf("key:\n");
	phex(newKey);
	printf("\n");

	// print the resulting cipher as 4 x 16 byte strings
	printf("ciphertext:\n");
	struct AES_ctx ctx;
	AES_init_ctx(&ctx, newKey);
	for (i = (uint8_t)0; i < (uint8_t)5; ++i)
	{
		AES_ECB_encrypt(&ctx, in + (i * (uint8_t)16));
	}

	for (i = (uint8_t)0; i < (uint8_t)5; ++i)
	{
		phex(in + (i * (uint8_t)16));
	}
	printf("\n");
	WINPAUSE;
}


void Decryption()
{

	uint8_t i;

	// 1286bit key
	uint8_t key[16] = { (uint8_t)0x2b, (uint8_t)0x7e, (uint8_t)0x15, (uint8_t)0x16, (uint8_t)0x28, (uint8_t)0xae, (uint8_t)0xd2, (uint8_t)0xa6, (uint8_t)0xab, (uint8_t)0xf7, (uint8_t)0x15, (uint8_t)0x88, (uint8_t)0x09, (uint8_t)0xcf, (uint8_t)0x4f, (uint8_t)0x3c };
	//Ciphered text
	uint8_t ciphered[80] = {
		(uint8_t)0x0e, (uint8_t)0xd9, (uint8_t)0xb0, (uint8_t)0x5b, (uint8_t)0xcd, (uint8_t)0xfa, (uint8_t)0x1e, (uint8_t)0xc2, (uint8_t)0x93, (uint8_t)0xec, (uint8_t)0x90, (uint8_t)0xba, (uint8_t)0xa6, (uint8_t)0x4f, (uint8_t)0x19, (uint8_t)0xa0,
		(uint8_t)0x9a, (uint8_t)0xe3, (uint8_t)0x60, (uint8_t)0xa3, (uint8_t)0xb0, (uint8_t)0x1f, (uint8_t)0x32, (uint8_t)0xb9, (uint8_t)0xdd, (uint8_t)0x7d, (uint8_t)0xf3, (uint8_t)0x73, (uint8_t)0x94, (uint8_t)0x6f, (uint8_t)0x2d, (uint8_t)0xe3,
		(uint8_t)0xd9, (uint8_t)0xf3, (uint8_t)0x85, (uint8_t)0x55, (uint8_t)0xac, (uint8_t)0x08, (uint8_t)0x18, (uint8_t)0x7f, (uint8_t)0xca, (uint8_t)0xe8, (uint8_t)0x4c, (uint8_t)0x6d, (uint8_t)0x5b, (uint8_t)0x10, (uint8_t)0x6a, (uint8_t)0x86,
		(uint8_t)0xd7, (uint8_t)0xca, (uint8_t)0xed, (uint8_t)0x8b, (uint8_t)0xf6, (uint8_t)0xc9, (uint8_t)0x92, (uint8_t)0x6f, (uint8_t)0x07, (uint8_t)0x2a, (uint8_t)0x31, (uint8_t)0x8f, (uint8_t)0x36, (uint8_t)0x1e, (uint8_t)0xbc, (uint8_t)0x4f,
		(uint8_t)0x4d, (uint8_t)0x40, (uint8_t)0x3b, (uint8_t)0xfe, (uint8_t)0x44, (uint8_t)0xd0, (uint8_t)0x8d, (uint8_t)0x69, (uint8_t)0xfb, (uint8_t)0x0d, (uint8_t)0x53, (uint8_t)0xb9, (uint8_t)0x4b, (uint8_t)0x33, (uint8_t)0x7c, (uint8_t)0xa9};
	//Plain text
	uint8_t out[80] = {
		(uint8_t)0x55, (uint8_t)0x89, (uint8_t)0xe5, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x4c, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x01, (uint8_t)0xc6,
		(uint8_t)0x00, (uint8_t)0x4f, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x02, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x50, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0,
		(uint8_t)0x03, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x45, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x04, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x52, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08,
		(uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x05, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x53, (uint8_t)0x8b, (uint8_t)0x45, (uint8_t)0x08, (uint8_t)0x83, (uint8_t)0xc0, (uint8_t)0x06, (uint8_t)0xc6, (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x90,
		(uint8_t)0x5d, (uint8_t)0xc3, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14, (uint8_t)0x14 };


	char input[16];
	printf("\nEnter a password: ");
	scanf("%s", &input);


	//Xored key with password 
	int len = strlen(input);
	uint8_t* newKey = (uint8_t *)malloc(sizeof(uint8_t *) *len);
	for (i = (uint8_t)0; i < (uint8_t)len; ++i)
	{
		newKey[i] = (uint8_t)(key[i] ^ input[i]);
	}

	printf("key:\n");
	phex(newKey);
	printf("\n");
	struct AES_ctx ctx;
	AES_init_ctx(&ctx, newKey);

	for (i = (uint8_t)0; i < (uint8_t)5; ++i)
	{
		AES_ECB_decrypt(&ctx, ciphered + (i * (uint8_t)16));
	}
	printf("Should output the same result\n");
	for (int i = 0; i < 66; i++)
	{
		printf("%.2X->%.2X\n", ciphered[i], out[i]);
	}
	printf("\n");

	uint8_t * decrypted = (uint8_t *)malloc(sizeof(uint8_t *) * 66);
	for (int i = 0; i < 66; i++)
	{
		decrypted[i] = ciphered[i];
	}

	int length = 66;
	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);
	auto const page_size = system_info.dwPageSize;

	// prepare the memory in which the machine code will be put (it's not executable yet):
	auto const buffer = VirtualAlloc(nullptr, page_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	// copy the machine code into that memory:
	memcpy(buffer, decrypted, length);

	// mark the memory as executable:
	DWORD dummy;
	VirtualProtect(buffer, length, PAGE_EXECUTE_READ, &dummy);

	// interpret the beginning of the (now) executable memory as the entry
	// point of a function taking no arguments and returning a 4-byte int:
	auto const function_ptr = (void(*) (unsigned char *)) buffer;

	// call the function and store the result in a local std::int32_t object:
	unsigned char * c = (unsigned char *)malloc(sizeof(unsigned char(*)) * 7);

	function_ptr(c);

	// free the executable memory:
	VirtualFree(buffer, 0, MEM_RELEASE);

	printf("The result of the function is %s\n", c);
	WINPAUSE;
}


int main()
{
	//First part of the program
	//Encryption();
	printf("\n");
	//Second part of the program
	Decryption();

	return 0;
}

