
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
		int currentIndex = letterInChunkIndex;
		int chunkNumber = 0;
		while (currentIndex < encryptedMessage.size()) {
			message += encryptedMessage.at(currentIndex);
			currentIndex += chunkLength;
			if (chunkNumber < remainder) {
				currentIndex++;
			}
			chunkNumber++;
		}
	}

	int index = chunkLength;
	for (int lettersRemaining = 0; lettersRemaining < remainder; lettersRemaining++) {
		message += encryptedMessage.at(index);
		index += chunkLength + 1;
	}
	
	return message;
}

int main()
{
	string message = "Happy Wednesday!";

	string encryptedMessage = encrypt(message, 3);

	cout << encryptedMessage << endl;

	cout << decrypt(encryptedMessage, 3) << endl;

	return 0;
}
