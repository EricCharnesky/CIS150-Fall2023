
#include <iostream>
#include <string>

using namespace std;

string encrypt(string message, int stride = 1) 
{
	string encryptedMessage = "";

	for (int startingIndex = 0; startingIndex < stride; startingIndex++) {
		for (int index = startingIndex; index < message.size(); index += stride) {
			encryptedMessage += message.at(index);
		}
	}

	for (int index = 0; index < encryptedMessage.size(); index++) {
		encryptedMessage.at(index) = encryptedMessage.at(index) + index;
	}

	return encryptedMessage;
}

string decrypt(string encryptedMessage, int stride = 1)
{
	string message = "";

	for (int index = 0; index < encryptedMessage.size(); index++) {
		encryptedMessage.at(index) = encryptedMessage.at(index) - index;
	}

	int chunkLength = encryptedMessage.size() / stride;
	int remainder = encryptedMessage.size() % stride;

	for (int letterInChunkIndex = 0; letterInChunkIndex < chunkLength; letterInChunkIndex++) {
		for (int chunkIndex = 0; chunkIndex < stride; chunkIndex++) {
			// int index = chunkIndex * chunkLength
		}
	}
	
	


	return encryptedMessage;
}

int main()
{
	string message = "Happy Monday!";

	string encryptedMessage = encrypt(message, 3);

	cout << encryptedMessage << endl;

	cout << decrypt(encryptedMessage, 3) << endl;

	return 0;
}
