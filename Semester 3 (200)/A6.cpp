#include <iostream>
using namespace std;

template<class TKey, class TData>
struct Element {
    TKey key;
    TData data;
};

template <class TKey, class TData>
class Container {
    private:
        int maxLength;
        int length;
        int iterator;
        Element<TKey, TData> *data;

    public:
        Container() {
            maxLength = 16;
            iterator = 0;
            length = 0;
            data = new Element<TKey, TData>[maxLength];
        }
        Container(int num) {
            maxLength = num;
            iterator = 0;
            length = 0;
            data = new Element<TKey, TData>[maxLength];
        }
        void push_back(Element<TKey, TData> element) {
            if (length >= maxLength) throw "container full";

            data[length] = element;

            length++;
        }
        Element<TKey, TData> front() const {
            if (!length) throw "container empty.";

            return data[0];
        }
        Element<TKey, TData> back() const {
            if (!length) throw "container empty";

            return data[length - 1];
        }
        Element<TKey, TData> get_next() {
            if (iterator + 1 >= length) throw "end of container";

            return data[iterator++];
        }
        void start() {
            if (!length) throw "container empty";

            iterator = 0;
        }
        int size() {
            return length;
        }
        int max_size() {
            return maxLength;
        }
        Element<TKey, TData> operator[](TKey key) {
            Element<TKey, TData> element;
            bool found = false;

            for (int i = 0; i < length; i++) {
                if (data[i].key == key) {
                    element = data[i];
                    found = true;

                    iterator = i + 1;
                    break;
                }
            }

            if (!found) throw "key not found";

            return element;
        }
};

int main() {
	Container <string,int> cc;
	Element <string,int> ee;
	cout << "*** starting test"<< endl;
	ee.key = "aaa";
	ee.data = 111;
	cc.push_back(ee);
	ee.key = "bbb";
	ee.data = 222;
	cc.push_back(ee);
	ee.key = "ccc";
	ee.data = 333;
	cc.push_back(ee);
	ee.key = "ddd";
	ee.data = 444;
	cc.push_back(ee);
	ee.key = "eee";
	ee.data = 555;
	cc.push_back(ee);
	ee.key = "fff";
	ee.data = 666;
	cc.push_back(ee);
	cout << "max size " << cc.max_size() << endl;
	cout << "current size " << cc.size() << endl;
	cc.start();
	cout << "*** iteration through all elements" << endl;
	try
	{
		while (true)
		{
			ee = cc.get_next();
			cout << ee.key << "*" << ee.data << endl;
		}
	}
	catch (const char s[])
	{
		cout <<"end of container reached -->" << s << "<--" << endl;
	}
	cout << "*** direct retrieval of key bbb" << endl;
	ee = cc["bbb"];
	cout << ee.key << "*" << ee.data << endl;
	cout << "*** direct retrieval of key abc" << endl;
	try
	{
		ee = cc["abc"];
	}
	catch (const char s[])
	{
		cout << "key not found condition -->" << s << "<--" << endl;
	}
	cout << "*** direct retrieval of key ddd" << endl;
	ee = cc["ddd"];
	cout << ee.key << "*" << ee.data << endl;
	cout << "*** iteration from that point forward" << endl;
	try
	{
		while (true)
		{
			ee = cc.get_next();
			cout << ee.key << "*" << ee.data << endl;
		}
	}
	catch (const char s[])
	{
		cout <<"end of container reached -->" << s << "<--" << endl;
	}
	return 0;
}
