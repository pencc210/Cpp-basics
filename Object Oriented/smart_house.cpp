
#include <iostream>
using namespace std;

class Device {
    string deviceName;
    bool status;

    public: 
    Device (string name) : deviceName(name), status(false) {} //Constructor initializes in off
    //Getters and setters
    bool getStatus(){
        return status;
    }
    void setStatus(bool s){
        status = s;
    }
    string getDeviceName(){
        return deviceName;
    }

    virtual void displayStatus() = 0; //Pure virtual fx (makes device an abstract class)

};

class SmartDevice { //To track energy consumption and test multiple inheritance

    int energyConsumption;

    public:

    SmartDevice() : energyConsumption(0) {}

    void setEnergyConsumption(int energy){
        energyConsumption = energy;
    }
    int getEnergyConsumption(){
        return energyConsumption;
    }
};

class SmartLight : public virtual Device, public virtual SmartDevice {

    public: 
    SmartLight (string name) : Device(name), SmartDevice() {} //Constructor linked to base class

    void turnOn(){
        setStatus(true);
    }
    void turnOff(){
        setStatus(false);
    }

    void displayStatus() override{
        cout << "Smart Light: " << getDeviceName() << " is "
        << (getStatus() ? "on, " : "off, ") 
        << "Energy consumption: " << getEnergyConsumption() << endl; 
    }
};

class SmartThermostat : public virtual Device, public virtual SmartDevice {

    int temperature;

    public:
    SmartThermostat (string name) : Device(name), SmartDevice(), temperature(0) {}

    void setTemperature(int temp){
        temperature = temp;
    }
    int getTemperature(){
        return temperature;
    }
    void displayStatus() override{
        cout << "Smart thermostat: " << getDeviceName() << " is "
        << (getStatus() ? "on," : "off,") << " Temperature: " << temperature 
        << "ºC, " << "Energy consumption: " << getEnergyConsumption() << endl; 
    }
};

class SmartSecurityCamera : public Device{

    public: 
    SmartSecurityCamera(string name) : Device(name) {}

    void startRecording(){
        setStatus(true);
    }
    void stopRecording(){
        setStatus(false);
    }

    void displayStatus() override{
        cout << "Smart Security Camera: " << getDeviceName() << " is "
        << (getStatus() ? "recording" : "not recording") << endl; 
    }

};

int main(){

    SmartLight light("Light 1"); 
    SmartThermostat thermo("T1");
    SmartSecurityCamera camera("C1");

    int size = 3;
    Device* arr[3] = {&light, &thermo, &camera}; //Array of pointers
    
    for(int i = 0; i < size; i++){
        arr[i]->displayStatus();
    }





    return 0;
}