#include <stdio.h>

int main(int argc, char* argv[]) {
	const int Buffer = 256;
	char Rec[Buffer];
	size_t Bytes_In, Bytes_Out;
	if (argc != 2) {
		printf("More Than 1 Or None Files Given");
		return 1;
	}
	FILE* Input = fopen(argv[1], "rb");
	if (Input == NULL) {
		printf("Error Reading File.");
		return 1;
	}
	FILE* Output = fopen("Copy.txt", "wb");
	if (Output == NULL) {
		printf("Copy File Not Created.");
		return 1;
	}
	while ((Bytes_In = fread(Rec, 1, Buffer, Input)) > 0) {
		Bytes_Out = fwrite(Rec, 1, Bytes_In, Output);
		if (Bytes_In != Bytes_Out) {
			printf("Critical Write Error.");
		}
	}
	fclose(Input);
	fclose(Output);
	return 0;
}