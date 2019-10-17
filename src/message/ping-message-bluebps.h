// C++ implementation of the Blue Robotics 'Ping' binary message protocol

//~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!
// THIS IS AN AUTOGENERATED FILE
// DO NOT EDIT
//~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!

#pragma once

#include "ping-message.h"

// TODO: should maybe be an enum
namespace BluebpsId
{
    static const uint16_t RESET_DEFAULTS = 9202;
    static const uint16_t ERASE_FLASH = 9201;
    static const uint16_t REBOOT = 9200;
    static const uint16_t TEMPERATURE_TIMEOUT = 9105;
    static const uint16_t EVENTS = 9107;
    static const uint16_t CELL_TIMEOUT = 9101;
    static const uint16_t STATE = 9106;
    static const uint16_t CURRENT_TIMEOUT = 9103;
    static const uint16_t CELL_VOLTAGE_MIN = 9100;
    static const uint16_t TEMPERATURE_MAX = 9104;
    static const uint16_t CURRENT_MAX = 9102;
    static const uint16_t TEMPERATURE_TIMEOUT = 9005;
    static const uint16_t LPF_SAMPLE_FREQUENCY = 9007;
    static const uint16_t CELL_VOLTAGE_MINIMUM = 9000;
    static const uint16_t LPF_SETTING = 9007;
    static const uint16_t CELL_VOLTAGE_TIMEOUT = 9001;
    static const uint16_t CURRENT_TIMEOUT = 9003;
    static const uint16_t CURRENT_MAX = 9002;
    static const uint16_t TEMPERATURE_MAX = 9004;
    static const uint16_t STREAM_RATE = 9006;
}

class bluebps_reset_defaults : public ping_message
{
public:
    bluebps_reset_defaults(const ping_message& msg) : ping_message { msg } {}
    bluebps_reset_defaults(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_reset_defaults() : ping_message { static_cast<uint16_t>(10) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(0); // payload size
        (uint16_t&)msgData[4] = 9202; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

};

class bluebps_erase_flash : public ping_message
{
public:
    bluebps_erase_flash(const ping_message& msg) : ping_message { msg } {}
    bluebps_erase_flash(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_erase_flash() : ping_message { static_cast<uint16_t>(10) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(0); // payload size
        (uint16_t&)msgData[4] = 9201; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

};

class bluebps_reboot : public ping_message
{
public:
    bluebps_reboot(const ping_message& msg) : ping_message { msg } {}
    bluebps_reboot(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_reboot() : ping_message { static_cast<uint16_t>(11) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(1); // payload size
        (uint16_t&)msgData[4] = 9200; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint8_t goto_bootloader() const { return (uint8_t&)msgData[headerLength + 0]; }
    void set_goto_bootloader(const uint8_t goto_bootloader) { (uint8_t&)msgData[headerLength + 0] = goto_bootloader; }
};

class bluebps_temperature_timeout : public ping_message
{
public:
    bluebps_temperature_timeout(const ping_message& msg) : ping_message { msg } {}
    bluebps_temperature_timeout(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_temperature_timeout() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9105; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t timeout() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_timeout(const uint16_t timeout) { (uint16_t&)msgData[headerLength + 0] = timeout; }
};

class bluebps_events : public ping_message
{
public:
    bluebps_events(const ping_message& msg) : ping_message { msg } {}
    bluebps_events(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_events() : ping_message { static_cast<uint16_t>(16) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(6); // payload size
        (uint16_t&)msgData[4] = 9107; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t voltage() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_voltage(const uint16_t voltage) { (uint16_t&)msgData[headerLength + 0] = voltage; }
    uint16_t current() const { return (uint16_t&)msgData[headerLength + 2]; }
    void set_current(const uint16_t current) { (uint16_t&)msgData[headerLength + 2] = current; }
    uint16_t temperature() const { return (uint16_t&)msgData[headerLength + 4]; }
    void set_temperature(const uint16_t temperature) { (uint16_t&)msgData[headerLength + 4] = temperature; }
};

class bluebps_cell_timeout : public ping_message
{
public:
    bluebps_cell_timeout(const ping_message& msg) : ping_message { msg } {}
    bluebps_cell_timeout(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_cell_timeout() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9101; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t timeout() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_timeout(const uint16_t timeout) { (uint16_t&)msgData[headerLength + 0] = timeout; }
};

class bluebps_state : public ping_message
{
public:
    bluebps_state(const ping_message& msg) : ping_message { msg } {}
    bluebps_state(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_state(uint8_t cell_voltages_length
) : ping_message { static_cast<uint16_t>(20 + cell_voltages_length) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(10 + cell_voltages_length); // payload size
        (uint16_t&)msgData[4] = 9106; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t battery_voltage() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_battery_voltage(const uint16_t battery_voltage) { (uint16_t&)msgData[headerLength + 0] = battery_voltage; }
    uint16_t battery_current() const { return (uint16_t&)msgData[headerLength + 2]; }
    void set_battery_current(const uint16_t battery_current) { (uint16_t&)msgData[headerLength + 2] = battery_current; }
    uint16_t battery_temperature() const { return (uint16_t&)msgData[headerLength + 4]; }
    void set_battery_temperature(const uint16_t battery_temperature) { (uint16_t&)msgData[headerLength + 4] = battery_temperature; }
    uint16_t cpu_temperature() const { return (uint16_t&)msgData[headerLength + 6]; }
    void set_cpu_temperature(const uint16_t cpu_temperature) { (uint16_t&)msgData[headerLength + 6] = cpu_temperature; }
    uint8_t flags() const { return (uint8_t&)msgData[headerLength + 8]; }
    void set_flags(const uint8_t flags) { (uint8_t&)msgData[headerLength + 8] = flags; }
    uint8_t cell_voltages_length() const { return (uint8_t&)msgData[headerLength + 9]; }
    //TODO do this in constructor (const)
    void set_cell_voltages_length(const uint8_t cell_voltages_length) { (uint8_t&)msgData[headerLength + 9] = cell_voltages_length;}
    uint16_t* cell_voltages() const { return (uint16_t*)(msgData+headerLength+10); }
    void set_cell_voltages_at(const uint16_t i, const uint16_t data) { (uint16_t&)msgData[headerLength + 10 + i] = data; }
};

class bluebps_current_timeout : public ping_message
{
public:
    bluebps_current_timeout(const ping_message& msg) : ping_message { msg } {}
    bluebps_current_timeout(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_current_timeout() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9103; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t timeout() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_timeout(const uint16_t timeout) { (uint16_t&)msgData[headerLength + 0] = timeout; }
};

class bluebps_cell_voltage_min : public ping_message
{
public:
    bluebps_cell_voltage_min(const ping_message& msg) : ping_message { msg } {}
    bluebps_cell_voltage_min(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_cell_voltage_min() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9100; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t limit() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_limit(const uint16_t limit) { (uint16_t&)msgData[headerLength + 0] = limit; }
};

class bluebps_temperature_max : public ping_message
{
public:
    bluebps_temperature_max(const ping_message& msg) : ping_message { msg } {}
    bluebps_temperature_max(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_temperature_max() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9104; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t limit() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_limit(const uint16_t limit) { (uint16_t&)msgData[headerLength + 0] = limit; }
};

class bluebps_current_max : public ping_message
{
public:
    bluebps_current_max(const ping_message& msg) : ping_message { msg } {}
    bluebps_current_max(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_current_max() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9102; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t limit() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_limit(const uint16_t limit) { (uint16_t&)msgData[headerLength + 0] = limit; }
};

class bluebps_temperature_timeout : public ping_message
{
public:
    bluebps_temperature_timeout(const ping_message& msg) : ping_message { msg } {}
    bluebps_temperature_timeout(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_temperature_timeout() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9005; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t timeout() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_timeout(const uint16_t timeout) { (uint16_t&)msgData[headerLength + 0] = timeout; }
};

class bluebps_lpf_sample_frequency : public ping_message
{
public:
    bluebps_lpf_sample_frequency(const ping_message& msg) : ping_message { msg } {}
    bluebps_lpf_sample_frequency(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_lpf_sample_frequency() : ping_message { static_cast<uint16_t>(14) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(4); // payload size
        (uint16_t&)msgData[4] = 9007; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint32_t sample_frequency() const { return (uint32_t&)msgData[headerLength + 0]; }
    void set_sample_frequency(const uint32_t sample_frequency) { (uint32_t&)msgData[headerLength + 0] = sample_frequency; }
};

class bluebps_cell_voltage_minimum : public ping_message
{
public:
    bluebps_cell_voltage_minimum(const ping_message& msg) : ping_message { msg } {}
    bluebps_cell_voltage_minimum(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_cell_voltage_minimum() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9000; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t limit() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_limit(const uint16_t limit) { (uint16_t&)msgData[headerLength + 0] = limit; }
};

class bluebps_lpf_setting : public ping_message
{
public:
    bluebps_lpf_setting(const ping_message& msg) : ping_message { msg } {}
    bluebps_lpf_setting(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_lpf_setting() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9007; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t setting() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_setting(const uint16_t setting) { (uint16_t&)msgData[headerLength + 0] = setting; }
};

class bluebps_cell_voltage_timeout : public ping_message
{
public:
    bluebps_cell_voltage_timeout(const ping_message& msg) : ping_message { msg } {}
    bluebps_cell_voltage_timeout(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_cell_voltage_timeout() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9001; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t timeout() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_timeout(const uint16_t timeout) { (uint16_t&)msgData[headerLength + 0] = timeout; }
};

class bluebps_current_timeout : public ping_message
{
public:
    bluebps_current_timeout(const ping_message& msg) : ping_message { msg } {}
    bluebps_current_timeout(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_current_timeout() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9003; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t timeout() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_timeout(const uint16_t timeout) { (uint16_t&)msgData[headerLength + 0] = timeout; }
};

class bluebps_current_max : public ping_message
{
public:
    bluebps_current_max(const ping_message& msg) : ping_message { msg } {}
    bluebps_current_max(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_current_max() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9002; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t limit() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_limit(const uint16_t limit) { (uint16_t&)msgData[headerLength + 0] = limit; }
};

class bluebps_temperature_max : public ping_message
{
public:
    bluebps_temperature_max(const ping_message& msg) : ping_message { msg } {}
    bluebps_temperature_max(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_temperature_max() : ping_message { static_cast<uint16_t>(12) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(2); // payload size
        (uint16_t&)msgData[4] = 9004; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint16_t limit() const { return (uint16_t&)msgData[headerLength + 0]; }
    void set_limit(const uint16_t limit) { (uint16_t&)msgData[headerLength + 0] = limit; }
};

class bluebps_stream_rate : public ping_message
{
public:
    bluebps_stream_rate(const ping_message& msg) : ping_message { msg } {}
    bluebps_stream_rate(const uint8_t* buf, const uint16_t length) : ping_message { buf, length } {}
    bluebps_stream_rate() : ping_message { static_cast<uint16_t>(14) }
    {
        msgData[0] = 'B';
        msgData[1] = 'R';
        (uint16_t&)msgData[2] = static_cast<uint16_t>(4); // payload size
        (uint16_t&)msgData[4] = 9006; // ID
        msgData[6] = 0;
        msgData[7] = 0;
    }

    uint32_t rate() const { return (uint32_t&)msgData[headerLength + 0]; }
    void set_rate(const uint32_t rate) { (uint32_t&)msgData[headerLength + 0] = rate; }
};

