#ifndef NET_H
#define NET_H

#include<cstdint>
using std::uint8_t;

constexpr uint8_t PROTOCAL_VERSION = 1;

enum class cmd :uint8_t {
	HELLO = 0x01,
	HELLO_ACK = 0x02,
	MOVE = 0x03,
	MOVE_ACK = 0x04,
	TAKEBACK = 0x05,
	TAKEBACK_ACK = 0x06,
	DRAW = 0x07,
	DRAW_ACK = 0x08,
	RESIGN = 0x09,
	RESIGN_ACK = 0x0A,
	RESTART = 0x0B,
	RESTART_ACK = 0x0C,
	WIN = 0x0D,
	CHAT = 0x0E,
};

#pragma pack(push, 1)
struct PkgHeader {
	uint8_t version;
	uint8_t cmd;
	uint16_t length;
	uint32_t seq;
};
#pragma pack(pop)

struct MovePkg {
	uint8_t x;
	uint8_t y;
};

struct HelloPkg {
	uint8_t color;
};

enum class netstate { offline = 0, connecting, online };

#endif

