
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution11 {
	int[][] constraintsTable = new int[729][324];			//таблица ограничений
	List<String> headerRowList = new ArrayList<>();		//список заголовков строк
	Node head; // head of list
	List<Node> closedNodes = new ArrayList<>();	//список закрытых Нод
	List<Node> firstCoverNodes = new ArrayList<>();	//список первоначально закрытых Нод, на первом уровне
	List<Integer> numsCoveredStr = new ArrayList<>();
	int coverCnt = 0;
	
	class Node {	//Узел для связного списка
		String name;
        int data;
        Node next;
        Node prev;
        Node up;
        Node down;
        Node(int d, String name) { 
        	this.data = d; 
        	this.name = name;
        }
    };
	
	private int makeConstraintsTable(char[][] board){
		int rowNum = 0;
		int colNum = 0;
		//заполним таблицу нулями
		for(int i = 0; i < 729; i++){
			for(int j = 0; j < 324; j++){
				constraintsTable[i][j] = 0;
			}
		}
		//заполняем ограничения в ячейках
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] == '.'){
					for(int k = 1; k <= 9; k++){
						colNum = i*9 + j;						
						constraintsTable[rowNum][colNum] = 1;
						rowNum++;
						//добавим в список заголовков строк
						headerRowList.add("R" + i + "C" + j + "#" + k);
					}
				} else {
					colNum = i*9 + j;						
					constraintsTable[rowNum][colNum] = 1;
					rowNum++;
					//добавим в список заголовков строк
					headerRowList.add("R" + i + "C" + j + "#" + board[i][j]);
				}
			}
		}
		//заполняем ограничения в строках
		rowNum = 0;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] == '.'){
					for(int k = 0; k < 9; k++){
						colNum = 81 + i + k*9;
						constraintsTable[rowNum][colNum] = 1;
						rowNum++;
					}
				} else {
					colNum = 81 + i + (board[i][j] - 48 - 1)*9;
					constraintsTable[rowNum][colNum] = 1;
					rowNum++;
				}
			}
		}
		//заполняем ограничения в столбцах
		rowNum = 0;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] == '.'){
					for(int k = 0; k < 9; k++){
						colNum = 162 + j + k*9;
						constraintsTable[rowNum][colNum] = 1;
						rowNum++;
					}
				} else {
					colNum = 162 + j + (board[i][j] - 48 - 1)*9;
					constraintsTable[rowNum][colNum] = 1;
					rowNum++;
				}
			}
		}	
		//заполняем ограничения в боксах
		rowNum = 0;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j] == '.'){
					for(int k = 0; k < 9; k++){
						//colNum = 243 + k + ((i/3)*3 + j/3) * 9;
						colNum = 243 + k*9 + ((i/3)*3 + j/3);	// 2 бокса в строке
						//System.out.println("Constr in box, colNum=" + colNum + ", rowNum=" + rowNum);
						constraintsTable[rowNum][colNum] = 1;
						rowNum++;
					}
				} else {
					colNum = 243 + (board[i][j] - 48 - 1)*9 + ((i/3)*3 + j/3);	//243 отступ от начала + (число в ячейке - 1) * большее число (9)
					constraintsTable[rowNum][colNum] = 1;					// + номер бокса (малый квадрат), отсчет с нуля 
					rowNum++;
				}
			}
		}
		
				//просмотрим таблицу ограничений
		for(int i = 0; i < 729; i++){
			for(int j = 0; j < 324; j++){
				System.out.print(constraintsTable[i][j] + ",");
			}
			System.out.println();
		}
		return rowNum;
	}
	
	//Adding a node from right 
    void addFromRight(Node node, int new_data, String name){
    	Node new_Node = new Node(new_data, name);
    	node.next = new_Node;
    	new_Node.prev = node;    	
    }
    
  //Adding a node from bottom
    void addFromBottom(Node node, int new_data, String name){
    	Node new_Node = new Node(new_data, name);
    	node.down = new_Node;
    	new_Node.up = node; 
    }
    
    //добавляем ноду в таблицу
    void addNodeToTable(int rowNum, int colNum, String name){
    	Node rowNode, colNode;
		rowNode = head;
		colNode = head;
		//перемещаемся на левую и верхнюю краюнюю ноды
		for(int i = 0; i <= rowNum; i++){rowNode = rowNode.down;}
		for(int i = 0; i <= colNum; i++){colNode = colNode.next;}
		while(rowNode.next != null){rowNode = rowNode.next;}
		while(colNode.down != null){colNode = colNode.down;}
		//создаем ноду и связываем ее с левой и верхней
		Node new_Node = new Node(1, name);
		rowNode.next = new_Node;
		new_Node.prev = rowNode;
		colNode.down = new_Node;
		new_Node.up = colNode;    
    }
    
    public void printlistRow(Node node){
        while (node != null) {
            System.out.print(node.name + " ");
            node = node.next;
        }
        System.out.println();
    }
    
    void printlistCol(Node node){
        while (node != null) {
            System.out.print(node.name + " ");
            node = node.down;
        }
        System.out.println();
    }
    
  //накрываем ноду
    void coverNode(Node node){
    	node.up.down = node.down;
    	if(node.down != null){
			node.down.up = node.up;
		} 
    }
    
    //раскрываем ноду
    void uncoverNode(Node node){
    	node.up.down = node;
		if(node.down != null){
			node.down.up = node;
		}
    }
    
  //накрываем строку 
    void coverStr(int numStr){
    	Node nextNode = head;
    	for(int i = 0; i < numStr; i++){
    		nextNode = nextNode.down;
    	}
    	if(nextNode != null){
    		System.out.println("Накрываю строку " + nextNode.name);
    		nextNode = nextNode.next;
    		while(nextNode != null){    			
    			nextNode.up.down = nextNode.down;
    			if(nextNode.down != null){
    				nextNode.down.up = nextNode.up;
    			} 
    			nextNode = nextNode.next;
    		}
    		numsCoveredStr.add(numStr);
    	} else {
    		System.out.println("nextNode equals null!");
    	}
    }
    
  //раскрываем строку
    void uncoverStr(int numStr){
    	Node nextNode = head;
    	for(int i = 0; i < numStr; i++){
    		nextNode = nextNode.down;
    	}
    	if(nextNode != null){
    		System.out.println("Раскрываю строку " + nextNode.name);
    		nextNode = nextNode.next;
    		while(nextNode != null){
    			nextNode.up.down = nextNode;
    			if(nextNode.down != null){
    				nextNode.down.up = nextNode;
    			}
    			nextNode = nextNode.next;
    		}
    	}
    }
    
    private void printClosedNodes(){
    	System.out.print("closedNodes: ");
    	for(Node closedNode : closedNodes){
    		System.out.print(closedNode.name + ", ");
    	}
    	System.out.println();
    }
    
    private void covStrInCol(Node tempNode) {
    	int numStrNode = 0;
    	System.out.println("Cover string in column. Handle node " + tempNode.name);
    	while(tempNode.up != null){tempNode = tempNode.up;}	//поднимемся вверх
    	while(tempNode.down != null){
    		tempNode = tempNode.down;
    		//numStrNode = Character.getNumericValue(tempNode.name.charAt(1)) + 1;
    		String[] parts = tempNode.name.split("_");
    		numStrNode = Integer.valueOf(parts[1]) + 1;
    		System.out.println("Cover string № " + numStrNode);
    		coverStr(numStrNode);
    		coverCnt++;
    	}
    }
    
    private boolean checkExactCover(){
    	int numStrNode = 0;
    	int[] checkArr = new int[324];	//размер массива по количеству столбцов
    	Arrays.fill(checkArr, 0);
    	for(Node node : closedNodes){
    		//numStrNode = Character.getNumericValue(node.name.charAt(1));
    		String[] parts = node.name.split("_");
    		numStrNode = Integer.valueOf(parts[1]);
    		System.out.println("array string: " + numStrNode + ", " + headerRowList.get(numStrNode));
    		for(int i = 0; i < 324; i++){	//размер по количеству столбцов
    			checkArr[i] = checkArr[i] + constraintsTable[numStrNode][i];
    		}
    	}
    	for(int i = 0; i < 324; i++){	//размер по количеству столбцов
    		if(checkArr[i] != 1){return false;}
    	}
    	return true;
    }
    
  //Ищем ноду с наименьшим количеством единиц
    private Node getNodeMinOnes(){    	
    	Node tempNode = head.next;
    	Node minNode = tempNode;
    	Node counterNode;
    	int cntOnes = 729;	//счетчик единиц по количеству строк
    	int cntr;
    	while(tempNode != null){
    		counterNode = tempNode;
    		cntr = 0;
    		if(counterNode.down != null){
	    		while(counterNode != null){
	    			counterNode = counterNode.down;
	    			cntr++;
	    		}
    		}
    		if((cntr < cntOnes) && (cntr > 0)){
    			cntOnes = cntr;
    			minNode = tempNode;
    		}
    		tempNode = tempNode.next;
    	}
    	
    	return minNode;
    }
    
    private boolean algorithmX(int level, int rowNum){	//level используем для определения уровня вложенности функции algorithmX
		Node minOnesNode;
    	Node tempNode = null;
    	//ищем столбец с самым меньшим количеством единиц (или нод)
    	minOnesNode = getNodeMinOnes();
    	System.out.println("Node with least amount ones: " + minOnesNode.name); 
    	tempNode = minOnesNode.down;
    	closedNodes.add(tempNode);
    	if(level == 0){
    		for(int i = firstCoverNodes.size() - 1; i >=0; i--){
    			uncoverNode(firstCoverNodes.get(i));
    		}
    		firstCoverNodes.add(tempNode);
    	}
    	level++;
    	printClosedNodes();
    	if(minOnesNode.down != null){
    		while(tempNode.prev != null){tempNode = tempNode.prev;}	//вернемся в начало
    		
    		System.out.println("Close node: " + tempNode.name);
    		while(tempNode.next != null){
    			//здесь будем проходить по строке и в каждом узле по столбцу и в каждом столбце закрываем строки 
    			tempNode = tempNode.next;
    			covStrInCol(tempNode);
    		}
    	} else {
    		System.out.println("No solutuins!");
    		return false;
    	}
    	System.out.println("coverCnt = " + coverCnt);
    	if(coverCnt < rowNum){	 //5 изменить на число строк   		
    		if(algorithmX(level, rowNum)){return true;}
    	} else {	//будем проверять на точное покрытие
    		if(checkExactCover()){
    			System.out.println("Есть решение!");
    			return true;
    		} else {
    			System.out.println("Нет точного покрытия!");
    			return false;
    		}
    	}
		
		return false;
	}

	public void solveSudoku(char[][] board) {
		Node nextNode;
		int rowNum;
		int numStrNode = 0;
		
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				System.out.print(board[i][j] + ", ");
			}
			System.out.println();
		}
		System.out.println("---------------");
		
		rowNum = makeConstraintsTable(board);
		
		head = new Node(0, "head");	//создаем головной Node
		nextNode = head;
		for(int i = 0; i < 324; i++){	// по количеству столбцов, создаем заголовочные Node для столбцов
			addFromRight(nextNode, i, "C_" + i);
			nextNode = nextNode.next;
		}
		//printlistRow(head);
		nextNode = head;
		for(int i = 0; i < rowNum; i++){	//создаем заголовочные Node для строк
			addFromBottom(nextNode, i, "R_" + i);
			nextNode = nextNode.down;
		}
		//printlistCol(head);
		//формируем Linked-List таблицу
		for(int i = 0; i < rowNum; i++){
			for(int j = 0; j < 324; j++){	// по количеству столбцов
				if(constraintsTable[i][j] > 0){	//если элемент таблицы равен 1 добавляем ноду
					addNodeToTable(i, j, "T_"+i + "_" +j);
				}
			}
		}
		//printlistCol(head.next.next.next.next.next.next.next.next.next);
		while(!algorithmX(0, rowNum)){
			//будем закрывать первые ноды, использовавшиеся раньше
			System.out.print("numsCoveredStr.size() = ");
			for(int i = 0; i < numsCoveredStr.size(); i++){System.out.print(numsCoveredStr.get(i) + ", ");}
			System.out.println();
			System.out.println("numsCoveredStr.size() = " + numsCoveredStr.size());
			if(numsCoveredStr.size() > 0){	//Раскрываем закрытые строки и очищаем список закрытых строк
				
				for(int i = numsCoveredStr.size() - 1; i >= 0; i--){
					uncoverStr(numsCoveredStr.get(i));
				}
			}
			numsCoveredStr.clear();
			closedNodes.clear();
			for(Node firstCoverNode : firstCoverNodes){
				coverNode(firstCoverNode);
			}
			coverCnt = 0;
		}
		
		for(Node node : closedNodes){			
			String[] parts = node.name.split("_");
    		numStrNode = Integer.valueOf(parts[1]);
    		int row;
			int col;
			char val;
			row = Character.getNumericValue(headerRowList.get(numStrNode).charAt(1));
			col = Character.getNumericValue(headerRowList.get(numStrNode).charAt(3));
			val = headerRowList.get(numStrNode).charAt(5);
			board[row][col] = val;
		}
		
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				int bo = board[i][j];
				System.out.print(" " + board[i][j] + ", ");
			}
			System.out.println();
		}
		System.out.println("---------------");
		
	}
}




