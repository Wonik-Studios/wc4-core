//Wc4: A smart connect 4 AI

/*
Last Edit: 2022-04-09

Authors:
Nathan Kim (Wonik Member)
Aryan Zafer (Wonik Member)
*/

#include <node.h>
#include <vector>

using std::vector;
class ConnectFourAI {
    public:
        // Takes in board as 2d array. Also takes in the player turn.
        // The parameter of recursionLevel will be important to determine whether to return
        // the best move or the evaluation of the position (it will return the best move when it is equal to 1)
        static int makeMoveAI(vector<vector<int>> board, bool isPlayerOneTurn, int recursionLevel) {
            int maxRecursion = 6;
            int bestChoiceVal = isPlayerOneTurn ? -200 : 200;
            int colBestChoice = 0;
            int result = checkForWin(board);

            if(result != 1){
                return result;
            }
            else if(recursionLevel == maxRecursion) {
                return evaluate(board);
            }

            for(int i=0; i < board[0].size(); i++) {
                if(board[0][i] == 0) {
                    int move = makeMoveAI(makeMove(board, i, isPlayerOneTurn), !isPlayerOneTurn, recursionLevel + 1);
                    if(isPlayerOneTurn && move == 200) {
                        if(recursionLevel == 1) {
                            return i;
                        }
                        return 200;
                    }
                    else if(!isPlayerOneTurn && move == -200) {
                        if(recursionLevel == 1) {
                            return i;
                        }
                        return -200;
                    }
                    else {
                        if(isPlayerOneTurn){
                            if(move > bestChoiceVal){
                                bestChoiceVal = move;
                                colBestChoice = i;
                            }
                        } else {
                            if(move < bestChoiceVal){
                                bestChoiceVal = move;
                                colBestChoice = i;
                            }
                        }
                    }
                }
            }

            if(recursionLevel == 1) {
                return colBestChoice;
            }
            return bestChoiceVal;
        }
        
        static int checkForWin(vector<vector<int>> board) {
            bool horizontalPossibilities[4];

            for(int i=0; i < 7; i++) {
                int playerOneCount = 0;
                int playerTwoCount = 0;
                for(int j=0; j < 6; j++) {
                    int token = board[board.size() - j - 1][i];
                    if(token == 0) {
                        break;
                    }
                    else if(token == 1) {
                        playerOneCount++;
                        playerTwoCount = 0;
                    } 
                    else {
                        playerTwoCount++;
                        playerOneCount = 0;
                    }

                    if(playerOneCount == 4) {
                        return 200;
                    }
                    else if(playerTwoCount == 4) {
                        return -200;
                    }
                }
            }

            for(int i=0; i < 6; i++) {
                bool isPossible = true;

                for(int j=0; j < 4; j++) {
                    if(horizontalPossibilities[j]) {
                        int count = 0;
                        int token = board[board.size() - i - 1][j];
                        
                        for(int z=0; z < 4; z++) {
                            if(board[board.size() - i - 1][j + z] == 0) {
                                int loc = j + z - 4;
                                if(j + z - 4 < 0) {
                                    loc = 0;
                                }

                                while(loc != j + z && loc < sizeof(horizontalPossibilities)) {
                                    horizontalPossibilities[loc] = false;
                                    loc++;
                                }
                                break;
                            }
                            else if(token != board[board.size() - i - 1][j + z]) {
                                break;
                            }
                            count++;
                        }

                        if(count == 4) {
                            if(token == 1) {
                                return 200;
                            } else {
                                return -200;
                            }
                        }
                    }
                }
            }

            for(int i=0; i < 3; i++) {
                int j = i;
                int col = 0;
                int playerOneCounter = 0;
                int playerTwoCounter = 0;

                while(board.size() - j >= 1) {
                    int tkn = board[board.size() - j - 1][col];
                    if(tkn == 1) {
                        playerOneCounter++;
                        playerTwoCounter = 0;
                    }
                    else if(tkn == 2) {
                        playerTwoCounter++;
                        playerOneCounter = 0;
                    }
                    else {
                        playerTwoCounter = 0;
                        playerOneCounter = 0;
                    }

                    if(playerOneCounter == 4) {
                        return 200;
                    }
                    else if(playerTwoCounter == 4) {
                        return -200;
                    }
                    col++;
                    j++;
                }
            }

            for(int i=0; i < 3; i++) {
                int j = i;
                int col = 6;
                int playerOneCounter = 0;
                int playerTwoCounter = 0;

                while(board.size() - j >= 1) {
                    int tkn = board[board.size() - j - 1][col];
                    if(tkn == 1) {
                        playerOneCounter++;
                        playerTwoCounter = 0;
                    }
                    else if(tkn == 2) {
                        playerTwoCounter++;
                        playerOneCounter = 0;
                    }
                    else {
                        playerTwoCounter = 0;
                        playerOneCounter = 0;
                    }

                    if(playerOneCounter == 4) {
                        return 200;
                    }
                    else if(playerTwoCounter == 4) {
                        return -200;
                    }
                    col--;
                    j++;
                }
            }

            for(int i=0; i < 3; i++) {
                int col = i + 1;

                int playerOneCount = 0;
                int playerTwoCount = 0;
                for(int row=0; row < board.size() - i; row++) {
                    int tkn = board[board.size() - row - 1][col];

                    if(tkn == 1) {
                        playerOneCount++;
                        playerTwoCount=0;
                    }
                    else if(tkn == 2) {
                        playerTwoCount++;
                        playerOneCount=0;
                    }
                    else {
                        playerOneCount = 0;
                        playerTwoCount = 0;
                    }

                    if(playerTwoCount == 4) {
                        return -200;
                    }
                    else if(playerOneCount == 4) {
                        return 200;
                    }
                    col++;
                }
            }

            for(int i=0; i < 3; i++) {
                int col = board[0].size() - i - 2;

                int playerOneCount = 0;
                int playerTwoCount = 0;
                for(int row=0; row < board.size() - i; row++) {
                    int tkn = board[board.size() - row - 1][col];

                    if(tkn == 1) {
                        playerOneCount++;
                        playerTwoCount = 0;
                    }
                    else if(tkn == 2) {
                        playerTwoCount++;
                        playerOneCount = 0;
                    }
                    else {
                        playerOneCount = 0;
                        playerTwoCount = 0;
                    }

                    if(playerTwoCount == 4) {
                        return -200;
                    }
                    else if(playerOneCount == 4) {
                        return 200;
                    }
                    col--;
                }
            }
            
            if(checkForDraw(board)) {
                return 0;
            } else {
                return 1;
            }
        }


    private:
        static vector<vector<int>> makeMove(vector<vector<int>> board, int col, bool isPlayerOneTurn) {
            // this assignment of board to boardCopy actually
            // creates a new instance of board and does not hold
            // a reference to it.
            for(int i=0; i < board.size(); i++) {
                if(board[board.size() - i - 1][col] == 0) {
                    // We will set the first occurence of an empty space with the correspondong
                    // token. To start with the bottom and to go up, i is taken away from the board size.
                    if(isPlayerOneTurn) {
                        board[board.size() - i - 1][col] = 1;
                        break;
                    } else {
                        board[board.size() - i - 1][col] = 2;
                        break;
                    }
                }
            }
            return board;
        }

        static int findMinMaxIdx(vector<int> arr, bool findMaxIdx) {
            int idx;
            int extreme;
            if(findMaxIdx) {
                for(int i=0; i < arr.size(); i++) {
                    if(arr[i] > extreme) {
                        idx = i;
                        extreme = arr[i];
                    }
                }
            } else {
                for(int i=0; i < arr.size(); i++) {
                    if(arr[i] < extreme) {
                        idx = i;
                        extreme = arr[i];
                    }
                }
            }
            return idx;
        }

        static int evaluate(vector<vector<int>> board) {
            int sumWeights = 0;
            for(int i=0; i < board[0].size(); i++) {
                for(int j=0; j < board.size(); j++) {
                    int tkn = board[j][i];
                    if(tkn != 0) {
                        break;
                    }
                    sumWeights += evaluateTkn(board, j, i);
                }
            }
            return sumWeights;
        }

        static int evaluateTkn(vector<vector<int>> board, int _row, int _col) {
            int sum = 0;
            int row = _row;
            int col = _col - 3 < 0 ? 0 : _col - 3;

            auto pointAddition = [&](int matchTkn, int count) {
                if(count == 1) {
                    sum += matchTkn == 1 ? 1 : -1;
                }
                else if(count == 2) {
                    sum += matchTkn == 1 ? 4 : -4;
                }
                else if(count == 3){
                    sum += matchTkn == 1 ? 15 : -15;
                }
            };

            for(;col <= _col; col++) {
                int count = 0;
                int matchTkn = -1;
                for(int j=0; j < 4; j++){
                    if(col + j < board[0].size()){
                        int tkn = board[row][col + j];
                        if(matchTkn == -1) {
                            if(tkn != 0) {
                                matchTkn = tkn;
                                count++;
                            }
                        }
                        else if(matchTkn == tkn) {
                            count++;
                        }
                        else {
                            count = 0;
                            break;
                        }
                    } else {
                        break;
                    }
                }
                
                pointAddition(matchTkn, count);
            }

            col = _col;
            row = _row - 3 < 0 ? 0 : _row - 3;

            for(;row <= _row; row++) {
                int count = 0;
                int matchTkn = -1;
                for(int j=0; j < 4; j++){
                    if(row + j < board.size()){
                        int tkn = board[row + j][col];
                        if(matchTkn == -1) {
                            if(tkn != 0) {
                                matchTkn = tkn;
                                count++;
                            }
                        }
                        else if(matchTkn == tkn) {
                            count++;
                        }
                        else {
                            count = 0;
                            break;
                        }
                    } else {
                        break;
                    }
                }
                
                pointAddition(matchTkn, count);
            }

            for(int i=0; i < 4; i++) {
                row = _row - i;
                col = _col - i;
                int count = 0;
                int matchTkn = -1;
                for(int j=0; j < 4; j++) {
                    if(row + j < board.size() && col + j < board[0].size()
                        && row + j >= 0 && col + j >=0){
                        int tkn = board[row + j][col + j];
                        if(matchTkn == -1) {
                            if(tkn != 0) {
                                matchTkn = tkn;
                                count++;
                            }
                        }
                        else if(matchTkn == tkn) {
                            count++;
                        }
                        else {
                            count = 0;
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }

                pointAddition(matchTkn, count);
            }

            for(int i=0; i < 4; i++) {
                row = _row - i;
                col = _col + i;
                int count = 0;
                int matchTkn = -1;
                for(int j=0; j < 4; j++) {
                    if(row + j < board.size() && col - j < board[0].size()
                        && row + j >= 0 && col - j >=0){
                        int tkn = board[row + j][col - j];
                        if(matchTkn == -1) {
                            if(tkn != 0) {
                                matchTkn = tkn;
                                count++;
                            }
                        }
                        else if(matchTkn == tkn) {
                            count++;
                        }
                        else {
                            count = 0;
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }

                pointAddition(matchTkn, count);
            }

            return sum;
        }

        

        static bool checkForDraw(vector<vector<int>> board) {
            for(int i=0; i < 7; i++) {
                if(board[0][i] == 0) {
                    return false;
                }
            }
            return true;
        }
};

namespace node_wrapper
{
    using v8::Array;
    using v8::Context;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::Value;

    vector<vector<int>> vector_intermediate(Isolate *isolate, Local<Array> array)
    {
        vector<vector<int>> final_vector;
        Local<Context> context = isolate->GetCurrentContext();

        for (int i = 0; i < array->Length(); i++)
        {
            Local<Array> row = Local<Array>::Cast(array->Get(context, i).ToLocalChecked());
            vector<int> new_row;

            for (int ii = 0; ii < row->Length(); ii++)
            {
                int value = row->Get(context, ii).ToLocalChecked()->IntegerValue(context).FromJust();
                new_row.push_back(value);
            }

            final_vector.push_back(new_row);
        }

        return final_vector;
    }

    void mmai_wrapper(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        vector<vector<int>> vector_board = vector_intermediate(isolate, Local<Array>::Cast(args[0]));
        args.GetReturnValue().Set(ConnectFourAI::makeMoveAI(vector_board, args[1]->BooleanValue(isolate), 1));
    }

    void cfw_wrapper(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        vector<vector<int>> vector_board = vector_intermediate(isolate, Local<Array>::Cast(args[0]));
        args.GetReturnValue().Set(ConnectFourAI::checkForWin(vector_board));
    }

    void Init(Local<Object> exports, Local<Object> module)
    {
        NODE_SET_METHOD(exports, "ai", mmai_wrapper);
        NODE_SET_METHOD(exports, "winCheck", cfw_wrapper);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}
