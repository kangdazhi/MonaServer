/* 
	Copyright 2013 Mona - mathieu.poux[a]gmail.com
 
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License received along this program for more
	details (or else see http://www.gnu.org/licenses/).

	This file is a part of Mona.
*/

#pragma once

#include "Mona/Mona.h"
#include "Mona/Invoker.h"
#include "Mona/DiffieHellman.h"
#include "Poco/Buffer.h"


namespace Mona {

#define COOKIE_SIZE 0x40

class RTMFPHandshake;
class RTMFPCookieComputing : public WorkThread, private Task {
public:
	RTMFPCookieComputing(RTMFPHandshake&	handshake,Invoker& invoker);
	~RTMFPCookieComputing();

	const UInt8			value[COOKIE_SIZE];
	DiffieHellman				diffieHellman;
	Poco::Buffer<UInt8>	initiatorKey;
	Poco::Buffer<UInt8>	sharedSecret;


private:
	void						run();
	void						handle();

	RTMFPHandshake&				_handshake;
};

} // namespace Mona