#pragma once
#include <iostream>

using namespace std;

// ascii art for title page
void mainMenuASCII() {
	std::cout << "          _____  _   _  _____             " << endl;
	std::cout << "         |_   _|| | | ||  ___|            " << endl;
	std::cout << "           | |  | |_| || |__              " << endl;
	std::cout << "           | |  |  _  ||  __|             " << endl;
	std::cout << "           | |  | | | || |___             " << endl;
	std::cout << "           \\_/  \\_| |_/\\____/             " << endl;
	std::cout << endl;
	std::cout << " _____  _____  _      _       ___  ______ " << endl;
	std::cout << "/  __ \\|  ___|| |    | |     / _ \\ | ___ \\" << endl;
	std::cout << "| /  \\/| |__  | |    | |    / /_\\ \\| |_/ /" << endl;
	std::cout << "| |    |  __| | |    | |    |  _  ||    / " << endl;
	std::cout << "| \\__/\\| |___ | |____| |____| | | || |\\ \\ " << endl;
	std::cout << " \\____/\\____/ \\_____/\\_____/\\_| |_/\\_| \\_|" << endl;
	std::cout << endl << endl;
}

// death screen message
void deathScreenASCII() {
	std::cout << "__  __   ____    __  __           __  __    ___  _    __    ______           ____     ____    ______    ____ " << endl;
	std::cout << "\\ \\/ /  / __ \\  / / / /          / / / /   /   || |  / /   / ____/          / __ \\   /  _/   / ____/   / __ \\" << endl;
	std::cout << " \\  /  / / / / / / / /          / /_/ /   / /| || | / /   / __/            / / / /   / /    / __/     / / / /" << endl;
	std::cout << " / /  / /_/ / / /_/ /          / __  /   / ___ || |/ /   / /___           / /_/ /  _/ /    / /___    / /_/ / " << endl;
	std::cout << "/_/   \\____/  \\____/          /_/ /_/   /_/  |_||___/   /_____/          /_____/  /___/   /_____/   /_____/  " << endl;
	std::cout << endl << endl;
}

// wizard NPC ascii
void kingsWizardNPCASCII()	 {
	std::cout << "                      ____" << endl;
	std::cout << "                     / ___`\\" << endl;
	std::cout << "         /|         ( (   \\ \\" << endl;
	std::cout << "    |^v^v  V|        \\ \\/) ) )" << endl;
	std::cout << "    \\  ____ /         \\_/ / /" << endl;
	std::cout << "    ,Y`    `,            / /" << endl;
	std::cout << "    ||  -  -)           { }" << endl;
	std::cout << "    \\\\   _\\ |           | |" << endl;
	std::cout << "     \\\\ / _`\\_         / /" << endl;
	std::cout << "     / |  ~ | ``\\     _|_|" << endl;
	std::cout << "  ,-`  \\    |  \\ \\  ,//(_}" << endl;
	std::cout << " /      |   |   | \\/  \\| |" << endl;
	std::cout << "|       |   |   | '   ,\\ \\" << endl;
	std::cout << "|     | \\   /  /\\  _/`  | |" << endl;
	std::cout << "\\     |  | |   | ``     | |" << endl;
	std::cout << " |    \\  \\ |   |        | |" << endl;
	std::cout << " |    |   |/   |        / /" << endl;
	std::cout << " |    |        |        | |" << endl;

}

// ascii art for the knight class selection
void swordAndShieldASCII() {
	std::cout << "   |^^^|    \t\\_________________/" << endl;
	std::cout << "    }_{     \t|       | |       |" << endl;
	std::cout << "    }_{     \t|       | |       |" << endl;
	std::cout << "/|_/---\\_|\\ \t|       | |       |" << endl;
	std::cout << "I _|\\_/|_ I \t|_______| |_______|" << endl;
	std::cout << "\\| |   | |/ \t|_______   _______|" << endl;
	std::cout << "   |   |    \t|       | |       |" << endl;
	std::cout << "   |   |    \t|       | |       |" << endl;
	std::cout << "   |   |    \t \\      | |      /" << endl;
	std::cout << "   |   |    \t  \\     | |     /" << endl;
	std::cout << "   |   |    \t   \\    | |    /" << endl;
	std::cout << "   |   |    \t    \\   | |   /" << endl;
	std::cout << "   |   |    \t     \\  | |  /" << endl;
	std::cout << "   |   |    \t      \\ | | /" << endl;
	std::cout << "   |   |    \t       \\| |/" << endl;
	std::cout << "   |   |    \t        \\_/" << endl;
	std::cout << "   \\   /    \t" << endl;
	std::cout << "    \\ /     \t" << endl;
	std::cout << "     Y      \t" << endl;
	
}

// ascii art for the warrior class selection
void greatswordASCII() {
	std::cout << "                                                            __" << endl;
	std::cout << "                                                              \\" << endl;
	std::cout << "                                                              ||        _" << endl;
	std::cout << "                                                             <||      /|" << endl;
	std::cout << "  ___________________________________________________________/||      |/" << endl;
	std::cout << " /                                                         //o|/\\/\\/\\||/\\" << endl;
	std::cout << "/__________________________________________________________\\o|||||||||/**\\" << endl;
	std::cout << "\\                                                          /o|||||||||\\**/" << endl;
	std::cout << " \\_________________________________________________________\\\\o|\\/\\/\\/||\\/" << endl;
	std::cout << "                                                             \\||      |\\" << endl;
	std::cout << "                                                             <||      \\|_" << endl;
	std::cout << "                                                              ||" << endl;
	std::cout << "                                                            __/" << endl;
}

// ascii art for the archer class selection
void bowAndArrowASCII() {
	std::cout << " ___          " << endl;
	std::cout << "|   \\           /\\" << endl;
	std::cout << "|    \\         /  \\" << endl;
	std::cout << "|     \\        \\__/" << endl;
	std::cout << "|      \\        ||" << endl;
	std::cout << "|       \\       ||" << endl;
	std::cout << "|        |      ||" << endl;
	std::cout << "|        |      ||" << endl;
	std::cout << "|        |      ||" << endl;
	std::cout << "|        |      ||" << endl;
	std::cout << "|       /       ||" << endl;
	std::cout << "|      /       /||\\" << endl;
	std::cout << "|     /       | || |" << endl;
	std::cout << "|    /        | || |" << endl;
	std::cout << "|___/         |/  \\|" << endl;
}

// ascii art for a small rat
void oneSmallRatASCII() {
	std::cout << "           (\\_/)" << endl;
	std::cout << "   .-\"\"-.-.-' a\\" << endl;
	std::cout << "  /  \\      _.--'" << endl;
	std::cout << " (\\  /_---\\\\_\\_" << endl;
	std::cout << "  `'-." << endl;
	std::cout << "   ,__)" << endl;
}

//ASCII for 2 small rats
void twoSmallRatsASCII() {
	std::cout << "           (\\_/)   \t           (\\_/)" << endl;
	std::cout << "   .-\"\"-.-.-' a\\ \t   .-\"\"-.-.-' a\\" << endl;
	std::cout << "  /  \\      _.--'  \t  /  \\      _.--'" << endl;
	std::cout << " (\\  /_---\\\\_\\_ \t (\\  /_---\\\\_\\_ " << endl;
	std::cout << "  `'-.              \t  `'-.              " << endl;
	std::cout << "   ,__)             \t   ,__)   " << endl;
}

//ASCII for 3 small rats
void threeSmallRatsASCII() {
	std::cout << "           (\\_/)   \t           (\\_/)    \t           (\\_/) " << endl;
	std::cout << "   .-\"\"-.-.-' a\\ \t   .-\"\"-.-.-' a\\  \t   .-\"\"-.-.-' a\\ " << endl;
	std::cout << "  /  \\      _.--'  \t  /  \\      _.--'   \t  /  \\      _.--'  " << endl;
	std::cout << " (\\  /_---\\\\_\\_ \t (\\  /_---\\\\_\\_  \t (\\  /_---\\\\_\\_ " << endl;
	std::cout << "  `'-.              \t  `'-.               \t  `'-.              " << endl;
	std::cout << "   ,__)             \t   ,__)              \t   ,__)             " << endl;
}

// Ascii art for big rat
void bigRatASCII() {
	std::cout << "               _     __,..---\"\"-._                 ';-," << endl;
	std::cout << "        ,    _/_),-\"`             '-.                `\\\\" << endl;
	std::cout << "       \\|.-\"` - _)                   '.                ||" << endl;
	std::cout << "       /`   a   ,                      \\              .'/" << endl;
	std::cout << "       '.___,__/                 .-'    \\_        _.-'.'" << endl;
	std::cout << "          |\\  \\      \\         /`        _`\"\"\"\"\"\"`_.-'" << endl;
	std::cout << "             _/;--._, >        |   --.__/ `\"\"\"\"\"\"`" << endl;
	std::cout << "           (((-'  __//`'-......-;\\      )" << endl;
	std::cout << "                (((-'       __//  '--. /" << endl;
	std::cout << "                          (((-'    __//" << endl;
	std::cout << "                                 (((-'" << endl;
}

// Ascii art for rat king
void ratKingASCII() {
	std::cout << "         __             _,-\"~^ \"--." << endl;
	std::cout << "       _// )      _,-\"~`           `." << endl;
	std::cout << "     .\" (/ `\"-, -\"`                  ;" << endl;
	std::cout << "    / 6                               ;" << endl;
	std::cout << "   /           ,   |\\/\\/\\/|  ,-\";     ; " << endl;
	std::cout << "  (,__.--.      \\  |______| /        ;" << endl;
	std::cout << "   //'   /`-.\\   |          |        `._________" << endl;
	std::cout << "     _.-'_/`  )  )--...,,,___\\     \\-----------,)" << endl;
	std::cout << "   (((\"~` _. - '.-'           __`-.   )       //" << endl;
	std::cout << "         (((\"`             (((--- ~\"`        //" << endl;
	std::cout << "                                            ((________________" << endl;
	std::cout << "                                            `----\"\"\"\"~~~~^^^```" << endl;
}

// AScii for room 9
void roomNineASCII() {
	std::cout << "                    \t               _     __,..---\"\"-._                 ';-,  \t" << endl;
	std::cout << "                    \t        ,    _/_),-\"`             '-.                `\\\\  \t" << endl;
	std::cout << "                    \t       \\|.-\"` - _)                   '.                || \t" << endl;
	std::cout << "                    \t       /`   a   ,                      \\              .'/ \t" << endl;
	std::cout << "                    \t       '.___,__/                 .-'    \\_        _.-'.'  \t" << endl;
	std::cout << "           (\\_/)   \t          |\\  \\      \\         /`        _`\"\"\"\"\"\"`_.-'   \t            (\\_/)   " << endl;
	std::cout << "   .-\"\"-.-.-' a\\ \t             _/;--._, >        |   --.__/ `\"\"\"\"\"\"`       \t    .-\"\"-.-.-' a\\ " << endl;
	std::cout << "  /  \\      _.--'  \t           (((-'  __//`'-......-;\\      )                \t   /  \\      _.--'  " << endl;
	std::cout << " (\\  /_---\\\\_\\_ \t                (((-'       __//  '--. /                 \t  (\\  /_---\\\\_\\_ " << endl;
	std::cout << "  `'-.              \t                          (((-'    __//                  \t   `'-.              " << endl;
	std::cout << "   ,__)             \t                                 (((-'                   \t    ,__)             " << endl;
}

// Ascii for dead adventurer
void deadNPCASCII() {
	std::cout << "      _____|~~\\_____      ________________" << endl;
	std::cout << "  _-~               \\    |     \\" << endl;
	std::cout << "  _-     X       /   |__/    \\  \\" << endl;
	std::cout << "  _-         )   |   |  |     \\  \\" << endl;
	std::cout << "  _-     X       \\   |--|      |  |" << endl;
	std::cout << " __-_______________ /__/_______|  |____________" << endl;
	std::cout << "(                |----         |  |" << endl;
	std::cout << " `---------------'--\\\\\\\\      .`--'" << endl;
	std::cout << "                              `||||" << endl << endl;
}

// Ascii for fountain
void fountainASCII() {
	std::cout << "                      .      .       .       ." << endl;
	std::cout << "  .   .       .          .      . .      .         .          .    " << endl;
	std::cout << "         .       .         .    .   .         .         .            " << endl;
	std::cout << "    .   .    .       .         . . .        .        .     .    ." << endl;
	std::cout << " .          .   .       .       . .      .        .  .              " << endl;
	std::cout << "      .  .    .  .       .     . .    .       . .      .   .        " << endl;
	std::cout << "    .            .    .     .   . .  .     .   .               ." << endl;
	std::cout << "     .               .  .    .  . . .    .  .                 ." << endl;
	std::cout << "                        . .  .  . . .  . ." << endl;
	std::cout << "                            . . . . . ." << endl;
	std::cout << "                              . . . ." << endl;
	std::cout << "                               I . I" << endl;
	std::cout << "                 _______________III_______________" << endl;
	std::cout << "                /    .       .  /\\/\\  .       .    \\" << endl;
	std::cout << "               ( ~~~ .  ~~~  .  \\  /  .  ~~~  . ~~~ )" << endl;
	std::cout << "                 \\SSSSSSSSSSSSSS \\/ SSSSSSSSSSSSSS/" << endl;
	std::cout << "                    \\ ======================= /" << endl;
	std::cout << "                        \\SSSSSSSSSSSSSSSSS/" << endl << endl;
}

// Ascii for the trap
void trapASCII() {
	std::cout << "    __                             __                                                                     __" << endl;
	std::cout << "   /  \\           __              /  \\                                            __                     /  \\" << endl;
	std::cout << "   \\__/          /  \\             \\__/                                           /  \\                    \\__/" << endl;
	std::cout << "                 \\__/                                                            \\__/ " << endl;
	std::cout << "                           __                           __" << endl;
	std::cout << "                          /  \\                         /  \\ " << endl;
	std::cout << "                          \\__/                         \\__/                                      __" << endl;
	std::cout << "                                                                                                /  \\ " << endl;
	std::cout << "                                                                                                \\__/" << endl;
	std::cout << "              __                              __                          __                                   __" << endl;
	std::cout << "             /  \\                            /  \\                        /  \\                                 /  \\" << endl;
	std::cout << "             \\__/                            \\__/                        \\__/                                 \\__/" << endl;

}

// ASCII for spike
void spikeASCII() {
	std::cout << "     /\\                            /\\                                                                            /\\" << endl;
	std::cout << "    /  \\                          /  \\                                    /\\                                    /  \\" << endl;
	std::cout << "   /    \\           /\\           /    \\                                  /  \\                                  /    \\" << endl;
	std::cout << "                   /  \\                                 /\\              /    \\                 /\\ " << endl;
	std::cout << "                  /    \\                               /  \\                                   /  \\" << endl;
	std::cout << "                                                      /    \\                                 /    \\" << endl;

}

//win page king npc ascii
void kingNPCASCII() {
	std::cout << "                             ." << endl;
	std::cout << "                            / \\" << endl;
	std::cout << "                           _\\ /_" << endl;
	std::cout << "                 .     .  (,'v`.)  .     ." << endl;
	std::cout << "                 \\)   ( )  ,' `.  ( )   (/" << endl;
	std::cout << "                  \\`. / `-'     `-' \\ ,'/" << endl;
	std::cout << "                   : '    _______    ' :" << endl;
	std::cout << "                   |  _,-'  ,-.  `-._  |" << endl;
	std::cout << "                   |,' ( )__`-'__( ) `.|" << endl;
	std::cout << "                   (|,-,'-._   _.-`.-.|)" << endl;
	std::cout << "                   /  /<( o)> <( o)>\\  \\" << endl;
	std::cout << "                   :  :     | |     :  :" << endl;
	std::cout << "                   |  |     ; :     |  |" << endl;
	std::cout << "                   |  |    (.-.)    |  |" << endl;
	std::cout << "                   |  |  ,' ___ `.  |  |" << endl;
	std::cout << "                   ;  |)/ ,'---'. \\(|  :" << endl;
	std::cout << "               _,-/   |/\\(       )/\\|   \\-._" << endl;
	std::cout << "         _..--'.-(    |   `-'''-'   |    )-.`--.._" << endl;
	std::cout << "                  `.  ;`._________,':  ,'" << endl;
	std::cout << "                 ,' `/               \\'`." << endl;
	std::cout << "                      `------.------'          " << endl;
}

// win page text
void winPageASCII() {
	std::cout << "__  ______  __  __   _       _______   __" << endl;
	std::cout << "\\ \\/ / __ \\/ / / /  | |     / /  _/ | / /" << endl;
	std::cout << " \\  / / / / / / /   | | /| / // //  |/ / " << endl;
	std::cout << " / / /_/ / /_/ /    | |/ |/ // // /|  /  " << endl;
	std::cout << "/_/\\____/\\____/     |__/|__/___/_/ |_/   " << endl << endl;
}