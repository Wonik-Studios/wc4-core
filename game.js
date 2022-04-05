class Game {
    constructor(){}

    generateBoard(columns, rows){
        this.board = []

        for (let i = 0; i < rows; i++){
            this.board[i] = []
            for (let ii = 0; ii < columns; ii++){
                this.board[i].push(0)
            }
        }
    }

    printBoard(){
        console.log("\n")
        for (let i = 0; i < this.board.length; i++){
            for (let ii = 0; ii < this.board[i].length; ii++){
                switch (this.board[i][ii]){
                    case 1:
                        process.stdout.write("O  ");
                    break;

                    case 2:
                        process.stdout.write("X  ");
                    break;

                    default:
                        process.stdout.write("-  ");
                    break;
                }
            }
            
            process.stdout.write("\n");
        }
    }

    makeMove(player, column){
        for (let i = this.board.length - 1; i >= 0; i--){
            if (this.board[i][column] === 0){
                this.board[i][column] = player
                return;
            }
        }
    }
}

module.exports = Game