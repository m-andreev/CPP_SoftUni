#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum class Direction {
    SOUTH, EAST, NORTH, WEST
};

enum Markers {
    INITIAL_POS = '@',
    SOUTH_DIR = 'S',
    EAST_DIR = 'E',
    NORTH_DIR = 'N',
    WEST_DIR = 'W',
    BEER = 'B',
    INVERTER = 'I',
    OBSTACLE = 'X',
    END_MARKER = '$',
    END_OF_MAP = '#',
TELEPORT = 'T'
};

std::string toString(Direction dir) {
    switch (dir) {
    case Direction::SOUTH:
        return "SOUTH";
    case Direction::EAST:
        return "EAST";
    case Direction::NORTH:
        return "NORTH";
    case Direction::WEST:
        return "WEST";
    default:
        std::cerr << "Received unsupported direction: " << static_cast<int>(dir)
            << std::endl;
        return "UNSUPPORTED";
    }
}

Direction toDirection(char tile) {
    if (tile == SOUTH_DIR) {
        return Direction::SOUTH;
    }
    if (tile == EAST_DIR) {
        return Direction::EAST;
    }
    if (tile == NORTH_DIR) {
        return Direction::NORTH;
    }
    if (tile == WEST_DIR) {
        return Direction::WEST;
    }

    std::cerr << "Error, unknown tile: " << tile << std::endl;
    return Direction::SOUTH;
}

struct Pos {
    Pos(int inputRow, int inputCol)
        : row(inputRow), col(inputCol) {

    }

    Pos() {

    }

    size_t row = 0;
    size_t col = 0;
};

Pos getFuturePos(const Pos& currDir, Direction dir) {
    switch (dir) {
    case Direction::SOUTH:
        return Pos(currDir.row + 1, currDir.col);
    case Direction::EAST:
        return Pos(currDir.row, currDir.col + 1);
    case Direction::NORTH:
        return Pos(currDir.row - 1, currDir.col);
    case Direction::WEST:
        return Pos(currDir.row, currDir.col - 1);
    default:
        std::cerr << "Received unsupported direction: " << static_cast<int>(dir)
            << std::endl;
        return Pos();
    }
}

class Map {
public:
    void readInput() {
        int rows = 0;
        int cols = 0;
        std::cin >> rows >> cols;
        std::cin.ignore();
        _data.resize(rows);
        for (auto& row : _data) {
            getline(std::cin, row);
        }
    }

    char getTile(const Pos& pos) {
        return _data[pos.row][pos.col];
    }

    Pos getInitialPos() const {
        const size_t rows = _data.size();
        for (size_t row = 0; row < rows; ++row) {
            const size_t cols = _data[row].size();
            for (size_t col = 0; col < cols; ++col) {
                if (_data[row][col] == INITIAL_POS) {
                    return Pos(row, col);
                }
            }
        }

        return Pos();
    }

    void findTeleports() {
        const size_t rows = _data.size();
        for (size_t row = 0; row < rows; ++row) {
            const size_t cols = _data[row].size();
            for (size_t col = 0; col < cols; ++col) {
                if (_data[row][col] == TELEPORT) {
                    _teleports.emplace_back(row, col);
                }
            }
        }
    }

    Pos getOppositeTeleport(const Pos& pos) {
        if (pos.row == _teleports[0].row && pos.col == _teleports[0].col) {
            return _teleports[1];
        }

        return _teleports[0];
    }

    void updateTile(const Pos& pos, char tileType) {
        _data[pos.row][pos.col] = tileType;
    }

private:
    std::vector<std::string> _data;
    std::vector<Pos> _teleports;
};

class DirectionStateMachine {
public:
    DirectionStateMachine() {
        _directions = { Direction::SOUTH, Direction::EAST, Direction::NORTH,
            Direction::WEST };
        _invertedDrections = { Direction::WEST, Direction::NORTH, Direction::EAST,
            Direction::SOUTH };

        _currDirs = &_directions;
    }

    void invertDirections() {
        _areDirsInverted = !_areDirsInverted;

        if (_areDirsInverted) {
            _currDirs = &_invertedDrections;
        }
        else {
            _currDirs = &_directions;
        }
    }

    Direction getNextDir() {
        ++_currDirIdx;
        if (_currDirIdx >= _currDirs->size()) {
            _currDirIdx = 0;
        }

        return _currDirs->at(_currDirIdx);
    }

    void updateDir(Direction dir) {
        _currDirIdx = std::find(_currDirs->begin(), _currDirs->end(), dir)
            - _currDirs->begin();
    }

    void reset() {
        _currDirIdx = std::numeric_limits<size_t>::max();
    }

private:
    std::vector<Direction> _directions;
    std::vector<Direction> _invertedDrections;
    std::vector<Direction>* _currDirs = nullptr;
    size_t _currDirIdx = 0;
    bool _areDirsInverted = false;
};

class Splender {
public:
    void setInitialPos(const Pos& pos) {
        _currPos = pos;
    }

    void act(Map& map) {
        const Pos futurePos = getFuturePos(_currPos, _currDir);
        const char futureTile = map.getTile(futurePos);
        _dirToPrint = _currDir;

        if (END_MARKER == futureTile) {
            _isRunning = false;
            return;
        }

        if (END_OF_MAP == futureTile) {
            _currDir = _dirStateMachine.getNextDir();
            act(map);
            return;
        }

        if (OBSTACLE == futureTile) {
            if (!_isBreakerModeActive) {
                _currDir = _dirStateMachine.getNextDir();
                act(map);
                return;
            }
        }

        _dirStateMachine.reset();
        _currPos = futurePos;

        if (OBSTACLE == futureTile) {
            if (_isBreakerModeActive) {
                map.updateTile(futurePos, ' ');
                return;
            }
        }

        if (shouldChangeDirection(futureTile)) {
            _currDir = toDirection(futureTile);
            _dirStateMachine.updateDir(_currDir);
            return;
        }

        if (BEER == futureTile) {
            _isBreakerModeActive = !_isBreakerModeActive;
            return;
        }

        if (INVERTER == futureTile) {
            _dirStateMachine.invertDirections();
            return;
        }

        if (TELEPORT == futureTile) {
            _currPos = map.getOppositeTeleport(_currPos);
            return;
        }
    }

    bool shouldChangeDirection(char currTile) const {
        if (currTile == SOUTH_DIR || currTile == EAST_DIR || currTile == NORTH_DIR
            || currTile == WEST_DIR) {
            return true;
        }

        return false;
    }

    void printMove() {
        std::cout << toString(_dirToPrint) << std::endl;
    }

    bool isRunning() const {
        return _isRunning;
    }

private:
    DirectionStateMachine _dirStateMachine;
    Direction _currDir = Direction::SOUTH;
    Direction _dirToPrint = Direction::SOUTH;
    Pos _currPos;
    bool _isRunning = true;
    bool _isBreakerModeActive = false;
};

class Game {
public:
    void readInput() {
        _map.readInput();
        _map.findTeleports();
        _splender.setInitialPos(_map.getInitialPos());
    }

    void act() {
        _splender.act(_map);
    }

    void printMove() {
        _splender.printMove();
    }

    bool isRunning() const {
        return _splender.isRunning();
    }

private:
    Map _map;
    Splender _splender;
};

int main() {
    Game game;
    game.readInput();
    while (game.isRunning()) {
        game.act();
        game.printMove();
    }

    return 0;
}


/*

The 9 rules of the new Splender system:
1) Splender starts from the place indicated by the @ symbol on the map and heads SOUTH.
2) Splender finishes his journey and dies when he reaches the suicide booth marked $.
3) Obstacles that Splender may encounter are represented by # or X.
4) When Splender encounters an obstacle, he changes direction using the following priorities: SOUTH, EAST, NORTH, and WEST. So he first tries to go SOUTH, if he cannot, then he will go EAST, if he still cannot, then he will go NORTH, and finally, if he still cannot, then he will go WEST.
5) Along the way, Splender may come across path modifiers that will instantaneously make him change direction. The S modifier will make him turn SOUTH from then on, E, to the EAST, N to the NORTH, and W to the WEST.
6) The circuit inverters (I on map) produce a magnetic field which will reverse the direction priorities that Splender should choose when encountering an obstacle. Priorities will become WEST, NORTH, EAST, SOUTH. If Splender returns to an inverter I, then priorities are reset to their original state (SOUTH, EAST, NORTH, WEST).
7) Splender can also find a few beers along his path (B on the map) that will give him strength and put him in “Breaker” mode. Breaker mode allows Splender to destroy and automatically pass through the obstacles represented by the character X (only the obstacles X). When an obstacle is destroyed, it remains so permanently and Splender maintains his course of direction. If Splender is in Breaker mode and passes over a beer again, then he immediately goes out of Breaker mode. The beers remain in place after Splender has passed.
8) 2 teleporters T may be present in the city. If Splender passes over a teleporter, then he is automatically teleported to the position of the other teleporter and he retains his direction and Breaker mode properties.
9) Finally, the space characters are blank areas on the map (no special behavior other than those specified above).


10 10
##########
#        #
#  S   W #
#        #
#  $     #
#        #
#@       #
#        #
#E     N #
##########



*/