#include <iostream>
#include <firebreak.h>
#include <fstream>
#include <cstring>

using namespace std;
#define s 9002
int main()
{
	cout << "Hello Firebreak." << endl;
	bool z[s];
	bool z2[s];
	firebreak::firebreakBool fb;
	bool rn = 0;
	for (size_t r = 0; r < s; r++) {
		z[r] = rn = !rn;
		fb.addBool(&z[r]);
	}
	memcpy(z2, z, sizeof(bool) * s);
	size_t bufferSize = fb.getBufferSize() + 1;
	char* zx = new char[bufferSize];
	memset(zx, 0x00, bufferSize);
	std::ofstream d("file.bin", std::ios::binary | std::ios::out);
	fb.writeToBuffer(zx, bufferSize);
	d.write((char*)zx, sizeof(char) * bufferSize);
	d.close();
	firebreak::firebreakBool fb2;
	for (size_t r = 0; r < s; r++) {
		fb2.addBool(&z2[r]);
	}
	fb2.readFromBuffer(zx, bufferSize);
	bool ok = true;
	for (size_t r = 0; r < s; r++) {
		if (z2[r] != z[r])ok = false;
	}
	cout << (ok ? "OK" : "ERR") << endl;
	delete zx;
	return 0;
}
