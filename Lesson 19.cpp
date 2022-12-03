#include<iostream>
#include<vector>
using namespace std;

class NotFoundException : public exception {
	string message;
public:
	NotFoundException(string message) : message(message) {}
	const char* what() const override {
		return message.c_str();
	}

};

class NotMemoryException : public exception {
	string message;
public:
	NotMemoryException(string message) : message(message) {}
	const char* what() const override {
		return message.c_str();
	}

};

class CreatSameException : public exception {
	string message;
public:
	CreatSameException(string message) : message(message) {}
	const char* what() const override {
		return message.c_str();
	}

};

class Disc {
protected:
	double current_size = 0;
	class File {
	private:
		double file_size = 0;
	public:
		string filename;
		string content;
		double write_speed() {
			return file_size / 10.0;
		}
		double getfile_size() {
			return file_size;
		}
		File(string filename, string content = "") {
			this->filename = filename;
			this->content = content;
			this->file_size = content.size();
		}


	};

	vector<File*>files;
public:
	const static double max_size;

	bool isExistsFile(string filename)
	{
		for (File* file : files)
		{
			if (file->filename == filename)
			{
				return true;
			}
			return false;
		}
	}

	virtual File& getFile(string filename) = 0;
	virtual void deleteFileContent(string filename) = 0;
	virtual void updateFilename(string oldfilename, string newfilename) = 0;
	virtual void hashFile(string filename) = 0;
	virtual void createFile(string filename, string content = "") = 0;
	virtual void setFileContent(string filename, string content = "") = 0;
};

const double Disc::max_size = 1024;

class SSD :public Disc {
public:
	virtual File& getFile(string filename) override
	{
		for (File* file : files)
		{
			if (file->filename == filename)
			{
				return *file;
			}
			throw NotFoundException("File not found!!");
		}
	}

	virtual void deleteFileContent(string filename) override
	{
		getFile(filename).content.clear();
		current_size -= getFile(filename).content.size();
	}

	virtual void updateFilename(string oldfilename, string newfilename) override
	{
		getFile(oldfilename).filename = newfilename;
	}

	void hashFile(string filename) override
	{
		getFile(filename).content.insert(0, "HUSH");
	}

	void createFile(string filename, string content = "") override
	{

		if (isExistsFile(filename)) {
			throw  CreatSameException("Don't creat same file");
		}
		File* newFile = new File(filename, content);
		if (max_size < current_size + newFile->getfile_size())
			throw NotMemoryException("Memory full");
		files.push_back(newFile);
		current_size += newFile->getfile_size();
		cout << "Write speed : " << newFile->write_speed() << " byte/second\n";
	}

	void setFileContent(string filename, string content = "") override
	{
		if (isExistsFile(filename)) {

			File& file = getFile(filename);
			current_size -= file.getfile_size();
			if (current_size + content.size() < max_size) {
				file.content = content;
				current_size += content.size();
				return;
			}
			throw NotMemoryException("Memory full");

		}
		throw NotFoundException("Fayl tapilmadi");
		cout << "Write speed : " << getFile(filename).write_speed() * 10 << " byte/second\n";
	}
};



class HDD :public Disc {
public:

	File& getFile(string filename) override 
	{
		for (File* file : files)
		{
			if (file->filename == filename)
			{
				return *file;
			}
			throw NotFoundException("File not found!!");
		}
	}

	void deleteFileContent(string filename) override
	{
		getFile(filename).content.clear();
		current_size -= getFile(filename).content.size();
	}

	void updateFilename(string oldfilename, string newfilename) override
	{
		getFile(oldfilename).filename = newfilename;
	}

	void hashFile(string filename) override
	{
		getFile(filename).content.insert(0, "HUSH");
	}

	void createFile(string filename, string content = "") override
	{

		if (isExistsFile(filename)) {
			throw  CreatSameException("Don't creat same file");
		}
		File* newFile = new File(filename, content);
		if (max_size < current_size + newFile->getfile_size())
			throw NotMemoryException("Memory full");
		files.push_back(newFile);
		current_size += newFile->getfile_size();
		cout << "Write speed : " << newFile->write_speed() << " byte/second\n";
	}

	void setFileContent(string filename, string content = "") override
	{
		if (isExistsFile(filename)) {

			File& file = getFile(filename);
			current_size -= file.getfile_size();
			if (current_size + content.size() < max_size) {
				file.content = content;
				current_size += content.size();
				return;
			}
			throw NotMemoryException("Memory full");

		}
		throw NotFoundException("Not File Founded");
		cout << "Write speed : " << getFile(filename).write_speed() << " byte/second\n";
	}
};



class OperationSystem {
	OperationSystem() {}
public:
	static void controlPC();
};


void OperationSystem::controlPC() {
	HDD hd;
	SSD ssd;
	try {
		hd.createFile("newtext.txt", "hello world");
		ssd.createFile("newtext.txt", "hello world");

		hd.getFile("newtext.txt");
		ssd.getFile("newtext.txt");
	}
	catch (const exception& ex) {
		cout << "Error : " << ex.what() << endl;
	}
}

void main()
{
	OperationSystem::controlPC();

}