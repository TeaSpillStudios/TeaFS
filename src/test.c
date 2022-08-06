#include <teafs.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	//TFSWriteData(argv[1], argv[2]);

	TFSWriteData("./saveFile", "Data1", 0);
	TFSWriteData("./saveFile", "\n", 1);
	TFSWriteData("./saveFile", "Data2", 1);
	TFSWriteData("./saveFile", "\n", 1);
	TFSWriteData("./saveFile", "Data3", 1);

	printf("\n\nFile output of \"%s\":\n%s\n", "./saveFile", TFSReadData("./saveFile.txt"));
	TFSFreeBuf();

	TFSMoveFile("./saveFile", "./newSaveFile");

	while (1) {

	}

	return 0;
}
