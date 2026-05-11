#include <link/desktop/abstract-link.h>
#include <ping-device-surveyor240.h>
#include <ping-message-all.h>
#include "ping-message-surveyor240.h"

#include "command-line/command-line.h"

#include "helper.h"

#include <cstdio>

/**
 * @brief Test ping 1D devices
 */
int main(int argc, char* argv[])
{
    if (!CommandLine::self()->run(argc, argv)) {
        return -1;
    }

    auto port = AbstractLink::openUrl(CommandLine::self()->connectionString);
    if (!port) {
        std::cerr << "Failed to open communication link with device" << std::endl;
        return -1;
    }
    Surveyor240 device = Surveyor240(*port.get());

    // Basic information
    PingDeviceTest::test("Device initialization", device.initialize());
    PingDeviceTest::test("Device type", static_cast<PingDeviceType>(device.device_information.device_type) == PingDeviceType::SURVEYOR240);
    PingDeviceTest::test("Device ID", device.device_id == 0);

    // PingDeviceTest::test("Ping protocol version",
    //     device.protocol_version.version_major == 1);

    printf("Firmware version: %d.%d.%d\n", device.device_information.firmware_version_major, device.device_information.firmware_version_minor, device.device_information.firmware_version_patch);

    device.set_set_ping_parameters(0, 1000, 1500, -1, 500, 0, 0, true, false, false, true, false, 240000, 200, 0, 1.5);
    surveyor240_yz_point_data* msg = reinterpret_cast<surveyor240_yz_point_data*>(device.waitMessage(Surveyor240Id::YZ_POINT_DATA, 10000));
    if (msg)
    {
      char buf[1000];
      msg->getMessageAsString(buf, 1000);
      std::cout << buf << std::endl;
      float* yz_data = msg->yz_point_data();
      for (unsigned int i = 0; i < msg->num_points(); i++)
      {
        std::cout << yz_data[i] << std::endl;
      }
    }
    else
    {
      std::cout << "no yz data" << std::endl;
    }
    device.set_set_ping_parameters(0, 1000, 1500, -1, 500, 0, 0, false, false, false, true, false, 240000, 200, 0, 1.5);

    return 0;
}
