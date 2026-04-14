#include <ping-message-common.h>
#include "ping-message-surveyor240.h"
#include "ping-device-surveyor240.h"

Surveyor240::~Surveyor240()
{
    if (atof_point_data_data.atof_point_data) {
        delete[] atof_point_data_data.atof_point_data;
    }
    if (yz_point_data_data.yz_point_data) {
        delete[] yz_point_data_data.yz_point_data;
    }
}

bool Surveyor240::initialize()
{
    if (!PingDevice::initialize()) {
        return false;
    }
    return true;
}

void Surveyor240::_handleMessage(const ping_message* message)
{
    switch (message->message_id()) {
    case Surveyor240Id::ATOF_POINT_DATA:
    {
        const surveyor240_atof_point_data* message_atof_point_data = static_cast<const surveyor240_atof_point_data*>(message);
        atof_point_data_data.pwr_up_msec = message_atof_point_data->pwr_up_msec();
        atof_point_data_data.utc_msec = message_atof_point_data->utc_msec();
        atof_point_data_data.listening_sec = message_atof_point_data->listening_sec();
        atof_point_data_data.sos_mps = message_atof_point_data->sos_mps();
        atof_point_data_data.ping_number = message_atof_point_data->ping_number();
        atof_point_data_data.ping_hz = message_atof_point_data->ping_hz();
        atof_point_data_data.pulse_sec = message_atof_point_data->pulse_sec();
        atof_point_data_data.flags = message_atof_point_data->flags();
        atof_point_data_data.num_points = message_atof_point_data->num_points();
        atof_point_data_data.reserved = message_atof_point_data->reserved();
        if (message_atof_point_data->num_points() > atof_point_data_data.atof_point_data_length) {
            if (atof_point_data_data.atof_point_data) {
                delete[] atof_point_data_data.atof_point_data;
            }
            atof_point_data_data.atof_point_data = new atof_t[message_atof_point_data->num_points()];
        }
        atof_point_data_data.atof_point_data_length = message_atof_point_data->num_points();
        memcpy(atof_point_data_data.atof_point_data, message_atof_point_data->atof_point_data(), message_atof_point_data->num_points());
    }
    break;
    case Surveyor240Id::ATTITUDE_REPORT:
    {
        const surveyor240_attitude_report* message_attitude_report = static_cast<const surveyor240_attitude_report*>(message);
        attitude_report_data.up_vec_x = message_attitude_report->up_vec_x();
        attitude_report_data.up_vec_y = message_attitude_report->up_vec_y();
        attitude_report_data.up_vec_z = message_attitude_report->up_vec_z();
        attitude_report_data.reserved_1 = message_attitude_report->reserved_1();
        attitude_report_data.reserved_2 = message_attitude_report->reserved_2();
        attitude_report_data.reserved_3 = message_attitude_report->reserved_3();
        attitude_report_data.utc_msec = message_attitude_report->utc_msec();
        attitude_report_data.pwr_up_msec = message_attitude_report->pwr_up_msec();
    }
    break;
    case Surveyor240Id::WATER_STATS:
    {
        const surveyor240_water_stats* message_water_stats = static_cast<const surveyor240_water_stats*>(message);
        water_stats_data.temperature = message_water_stats->temperature();
        water_stats_data.pressure = message_water_stats->pressure();
    }
    break;
    case Surveyor240Id::YZ_POINT_DATA:
    {
        const surveyor240_yz_point_data* message_yz_point_data = static_cast<const surveyor240_yz_point_data*>(message);
        yz_point_data_data.timestamp_msec = message_yz_point_data->timestamp_msec();
        yz_point_data_data.ping_number = message_yz_point_data->ping_number();
        yz_point_data_data.sos_mps = message_yz_point_data->sos_mps();
        yz_point_data_data.up_vec_x = message_yz_point_data->up_vec_x();
        yz_point_data_data.up_vec_y = message_yz_point_data->up_vec_y();
        yz_point_data_data.up_vec_z = message_yz_point_data->up_vec_z();
        yz_point_data_data.mag_vec_x = message_yz_point_data->mag_vec_x();
        yz_point_data_data.mag_vec_y = message_yz_point_data->mag_vec_y();
        yz_point_data_data.mag_vec_z = message_yz_point_data->mag_vec_z();
        yz_point_data_data.reserved_0 = message_yz_point_data->reserved_0();
        yz_point_data_data.reserved_1 = message_yz_point_data->reserved_1();
        yz_point_data_data.reserved_2 = message_yz_point_data->reserved_2();
        yz_point_data_data.reserved_3 = message_yz_point_data->reserved_3();
        yz_point_data_data.reserved_4 = message_yz_point_data->reserved_4();
        yz_point_data_data.reserved_5 = message_yz_point_data->reserved_5();
        yz_point_data_data.reserved_6 = message_yz_point_data->reserved_6();
        yz_point_data_data.reserved_7 = message_yz_point_data->reserved_7();
        yz_point_data_data.reserved_8 = message_yz_point_data->reserved_8();
        yz_point_data_data.reserved_9 = message_yz_point_data->reserved_9();
        yz_point_data_data.water_degC = message_yz_point_data->water_degC();
        yz_point_data_data.water_bar = message_yz_point_data->water_bar();
        yz_point_data_data.heave_m = message_yz_point_data->heave_m();
        yz_point_data_data.start_m = message_yz_point_data->start_m();
        yz_point_data_data.end_m = message_yz_point_data->end_m();
        yz_point_data_data.unused = message_yz_point_data->unused();
        yz_point_data_data.num_points = message_yz_point_data->num_points();
        if (message_yz_point_data->num_points() > yz_point_data_data.yz_point_data_length) {
            if (yz_point_data_data.yz_point_data) {
                delete[] yz_point_data_data.yz_point_data;
            }
            yz_point_data_data.yz_point_data = new float[message_yz_point_data->num_points()];
        }
        yz_point_data_data.yz_point_data_length = message_yz_point_data->num_points();
        memcpy(yz_point_data_data.yz_point_data, message_yz_point_data->yz_point_data(), message_yz_point_data->num_points());
    }
    break;

    default:
        break;
    }

    PingDevice::_handleMessage(message);
}

void Surveyor240::set_set_net_info(uint32_t _ntp_ip_address, uint32_t _subnet_mask, uint32_t _gateway_ip)
{
    surveyor240_set_net_info message;
    message.set_ntp_ip_address(_ntp_ip_address);
    message.set_subnet_mask(_subnet_mask);
    message.set_gateway_ip(_gateway_ip);
    writeMessage(message);
}

void Surveyor240::set_set_ping_parameters(int32_t _start_mm, int32_t _end_mm, float _sos_mps, int16_t _gain_index, int16_t _msec_per_ping, uint16_t _deprecated, uint8_t _diagnostic_injected_signal, bool _ping_enable, bool _enable_channel_data, bool _reserved_for_raw_data, bool _enable_yz_point_data, bool _enable_atof_data, int32_t _target_ping_hz, uint16_t _n_range_steps, uint16_t _reserved, float _pulse_len_steps)
{
    surveyor240_set_ping_parameters message;
    message.set_start_mm(_start_mm);
    message.set_end_mm(_end_mm);
    message.set_sos_mps(_sos_mps);
    message.set_gain_index(_gain_index);
    message.set_msec_per_ping(_msec_per_ping);
    message.set_deprecated(_deprecated);
    message.set_diagnostic_injected_signal(_diagnostic_injected_signal);
    message.set_ping_enable(_ping_enable);
    message.set_enable_channel_data(_enable_channel_data);
    message.set_reserved_for_raw_data(_reserved_for_raw_data);
    message.set_enable_yz_point_data(_enable_yz_point_data);
    message.set_enable_atof_data(_enable_atof_data);
    message.set_target_ping_hz(_target_ping_hz);
    message.set_n_range_steps(_n_range_steps);
    message.set_reserved(_reserved);
    message.set_pulse_len_steps(_pulse_len_steps);
    writeMessage(message);
}

void Surveyor240::set_utc_response(uint64_t _utc_msec, uint32_t _accuracy_msec)
{
    surveyor240_utc_response message;
    message.set_utc_msec(_utc_msec);
    message.set_accuracy_msec(_accuracy_msec);
    writeMessage(message);
}

