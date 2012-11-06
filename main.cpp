/**
 * @file main.cpp
 * @brief Simple but powerfull IRC server written in C++ using Boost libraries
 * @mainpage 
 * @author SkyWodd
 * @version 1.0
 * @see http://skyduino.wordpress.com/
 *
 * @section intro_sec Introduction
 * This program is a simple but powerfull IRC server written in C++ using Boost libraries.\n
 * The code in fully portable between linux, mac and windows !\n
 * Please also keep in mind that this project is a school project, not a final product !\n
 * Some of the IRC features are not implemented, and will not be (code & forget project).\n
 * \n
 * Please report bug to <skywodd at gmail.com>
 *
 * @section licence_sec Licence
 *  This program is free software: you can redistribute it and/or modify\n
 *  it under the terms of the GNU General Public License as published by\n
 *  the Free Software Foundation, either version 3 of the License, or\n
 *  (at your option) any later version.\n
 * \n
 *  This program is distributed in the hope that it will be useful,\n
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of\n
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n
 *  GNU General Public License for more details.\n
 * \n
 *  You should have received a copy of the GNU General Public License\n
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.\n
 */

/* Dependencies */
#include <iostream>
#include "Server.hpp"
#include "Configuration.hpp"

/**
 * Program entry point
 *
 * @param argc CLI arguments count
 * @param argv CLI arguments array
 * @return Error code
 */
int main(int argc, char** argv) {

	/* Try to start the server */
	try {

		/* Check command line arguments */
		if (argc != 3) {
			std::cerr << "Usage: Boost_IRC_server <address> <port>\n"
					<< std::endl;
			return 1;
		}

		/* Fill configuration structure */
		irc::Configuration configuration;
		configuration.svdomain = "irc.local";
		configuration.is_password_protected = false;
		configuration.server_ircop["root"] = "toor";
		configuration.ping_refresh_delay = 60;
		configuration.ping_timeout_delay = 120;
		configuration.nb_users_limit = 100;
		configuration.nb_channels_limit = 100;
		configuration.nb_join_limit = 10;
		configuration.is_ircop = false;
		configuration.is_receiving_wallops = true;
		configuration.is_receiving_notices = true;
		configuration.is_invisible = false;
		configuration.is_away = false;
		configuration.away_message = "I'm AFK";
		configuration.users_limit_per_channel = 10;
		configuration.is_private = false;
		configuration.is_secret = false;
		configuration.is_invite_only = false;
		configuration.topic_setby_op_only = true;
		configuration.no_outside_msg = true;
		configuration.is_moderated = false;

		/* Initialise the server */
		irc::Server server(argv[1], argv[2], configuration);

		/* Start the server */
		server.run();

	} catch (std::exception& e) { /* Catch exception */
		std::cerr << "[ERROR] Got exception : " << e.what() << std::endl;
	}

	/* Exit without error */
	return 0;
}


/* - TO DO LIST -
 * TODO Check IRC dump to match IRC protocol
 * TODO Make class to check validiy of nickname / channel name
 *
 *
 */
