#include <iostream>
#include <vector>

class ContactData {
    std::string phoneNumber;
    std::string contactName;
    std::string contactAddress;
public:
    std::string getPhoneNumber ()
    {
        return phoneNumber;
    }
    std::string getContactName ()
    {
        return contactName;
    }
    std::string getContactAddress ()
    {
        return contactAddress;
    }
    void setPhoneNumber (std::string enter)
    {
        phoneNumber = enter;
    }
    void setContactName (std::string enter)
    {
        contactName = enter;
    }
    void setContactAddress (std::string enter)
    {
        contactAddress = enter;
    }
};

class Phone {
    std::vector<ContactData*> contactData;
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
        ContactData* _contactData = new ContactData();
        _contactData->setPhoneNumber(phoneNumber);
        _contactData->setContactName(contactName);
        _contactData->setContactAddress(contactAddress);
        contactData.push_back(_contactData);
    }
    void call () {
        std::string whatEnter;
        std::cout << "what do you want enter:";
        std::cin >> whatEnter;
        if (whatEnter == "phone number") {
            std::string phoneNumber;
            std::cout << "enter phone number:";
            std::cin >> phoneNumber;
            for (int i = 0; i < contactData.size() - 1; i++) {
                if (phoneNumber == contactData[i]->getPhoneNumber()) {
                    std::cout << "CALL " << phoneNumber;
                }
            }
        }
        else if (whatEnter == "contact name") {
            std::string contactName;
            std::cout << "enter phone number:";
            std::cin >> contactName;
            for (int i = 0; i < contactData.size() - 1; i++) {
                if (contactName == contactData[i]->getContactName()) {
                    std::cout << "CALL " << contactData[i]->getPhoneNumber();
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
        for (int i = 0; i < contactData.size() - 1; i++) {
            if (phoneNumber == contactData[i]->getPhoneNumber()) {
                std::cout << "sms to " << phoneNumber << " with text: " << smsText;
            }
        }
    }
    void exit (int& programExit) {
        std::cout << "program end";
        programExit = 1;
        for (int i = 0; i < contactData.size(); i++) {
            delete contactData[i];
            contactData[i] = nullptr;
        }
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
