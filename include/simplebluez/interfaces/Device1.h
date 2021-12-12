#pragma once

#include <simpledbus/advanced/Interface.h>

#include <string>

namespace SimpleBluez {

class Device1 : public SimpleDBus::Interface {
  public:
    Device1(std::shared_ptr<SimpleDBus::Connection> conn, std::string path);
    ~Device1();

    // ----- METHODS -----
    void Connect();
    void Disconnect();

    // ----- PROPERTIES -----
    int16_t RSSI();
    uint16_t Appearance(); // On Bluez 5.53, this always returns 0.
    std::string Address();
    std::string Alias();
    std::string Name();
    std::map<uint16_t, std::vector<uint8_t>> ManufacturerData();
    bool Connected();
    bool ServicesResolved();

  protected:
    void property_changed(std::string option_name) override;

    int16_t _rssi;
    std::string _name;
    std::string _alias;
    std::string _address;
    bool _connected;
    bool _services_resolved;
    std::map<uint16_t, std::vector<uint8_t>> _manufacturer_data;
};

}  // namespace SimpleBluez
