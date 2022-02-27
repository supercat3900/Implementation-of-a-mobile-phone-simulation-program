#include <iostream>
#include <vector>



class ContactData {
    std::vector<std::string> phoneNumber;
    std::vector<std::string> contactName;
    std::vector<std::string> contactAddress;
public:
    std::string getPhoneNumber (int i)
    {
        if (i > phoneNumber.size() - 1) return phoneNumber.back();
        else if (i < 0) return phoneNumber[0];
        else return phoneNumber[i];
    }
    std::string getContactName (int i)
    {
        if (i > contactName.size() - 1) return contactName.back();
        if (i < 0) return contactName[0];
        return contactName[i];
    }
    std::string getContactAddress (int i)
    {
        if (i > contactAddress.size() - 1) return contactAddress.back();
        if (i < 0) return contactAddress[0];
        return contactAddress[i];
    }
    int getSize ()
    {
        return contactAddress.size();
    }
    void addContactData (std::string number, std::string name, std::string addres)
    {
        phoneNumber.push_back(number);
        contactName.push_back(name);
        contactAddress.push_back(addres);
    }
};

class Phone {
    ContactData* contactData = new ContactData();
public:
    void add () {
        std::string phoneNumber;
        std::string contactName;
        std::string contactAddress;
        std::cout << "enter phone number:";
        std::cin >> phoneNumber;
        std::cout << "enter phone contact name:";
        std::cin >> contactName;
        std::cout << "enter phone contact address:";
        std::cin >> contactAddress;
        if (11 == phoneNumber.size()) {
            for (int i = 0; i < 10; i++) {
                if (!(phoneNumber[i] >= '0' && phoneNumber[i] <= '9')) {
                    std::cout << "error";
                    return ;
                }
            }
        }
        contactData->addContactData(phoneNumber, contactName, contactAddress);
    }
    void call () {
        std::string whatEnter;
        std::cout << "what do you want enter:";
        std::cin >> whatEnter;
        if (whatEnter == "phone number") {
            std::string phoneNumber;
            std::cout << "enter phone number:";
            std::cin >> phoneNumber;
            for (int i = 0; i < contactData->getSize() - 1; i++) {
                if (phoneNumber == contactData->getPhoneNumber(i)) {
                    std::cout << "CALL " << phoneNumber;
                }
            }
        }
        else if (whatEnter == "contact name") {
            std::string contactName;
            std::cout << "enter phone number:";
            std::cin >> contactName;
            for (int i = 0; i < contactData->getSize() - 1; i++) {
                if (contactName == contactData->getContactName(i)) {
                    std::cout << "CALL " << contactData->getPhoneNumber(i);
                }
            };
        }
        else {
            std::cout << "error";
        }
    }
    void sms () {
        std::string smsText;
        std::string phoneNumber;
        std::cout << "enter phone number:";
        std::cin >> phoneNumber;
        std::cout << "enter sms text:";
        std::cin >> smsText;
        for (int i = 0; i < contactData->getSize() - 1; i++) {
            if (phoneNumber == contactData->getPhoneNumber(i)) {
                std::cout << "sms to " << phoneNumber << " with text: " << smsText;
            }
        }
    }
    void exit (int& programExit) {
        std::cout << "program end";
        programExit = 1;
        delete contactData;
        contactData = nullptr;
    }
};

int main() {
    Phone* phone = new Phone();
    for (;;) {
        int programExit = 0;
        std::string action = "";
        std::cout << "enter action:";
        std::cin >> action;
        if (action == "add") {
            phone->add();
        }
        else if (action == "call") {
            phone->call();
        }
        else if (action == "sms") {
            phone->sms();
        }
        if (programExit = 1) {
            delete phone;
            phone = nullptr;
            return 0;
        }
    }
}
