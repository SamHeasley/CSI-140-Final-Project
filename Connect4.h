#include <vector>

namespace connectFour {
	class connectFourHeader {
	public:
		bool winner = false;
		bool playerTurn = true;
		bool validOption;

		char empty = 32;

		std::vector<std::vector<char>> board = std::vector<std::vector<char>>(7, std::vector<char>(6, empty));

		int playerChoice;
		int gamemode;
	};
}
