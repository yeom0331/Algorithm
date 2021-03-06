# DFS-BFS

## 자료구조 기초
* 탐색 : 많은 양의 데이터 중에서 원하는 데이터를 찾는 과정
 	
* 자료구조 데이터를 표현하고 관리하고 처리하기 위한 구조
	* 삽입(PUSH): 데이터를 삽입
	* 삭제(POP): 데이터 삭제	
 	* 스택: 선입후출 구조 또는 후입선출 구조 	
 	* 큐: 선입선출 구조 	
 	* 재귀함수: 자신 자신을 다시 호출하는 함수(조건을 주지 않는다면 무한반복)
 	
## 탐색 알고리즘 DFS/BFS
* DFS: 깊이 우선 탐색이라고도 부르며, 그래프에서 깊은 부분을 우선적으로 탐색하는 알고리즘 	 
	* DFS 동작 과정 	 
		1. 탐색 시작 노드를 스택에 삽입하고 방문 처리를 한다.
		2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 있으면 그 인접 노드를 스택에 넣고 방문 처리를 한다. 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼낸다.
		3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복
 	 
	* DFS는 스택 자료구조에 기초한다는 점에서 재귀 함수를 이용했을 때 매우 간결하게 구현 가능
 	 
 	 
* BFS: 너비 우선 탐색, 쉽게 말해 가까운 노드부터 탐색하는 알고리즘 선업선출 방식인 큐 자료구조
 	 
	* BFS 동작 과정
		1. 탐색 시작 노드를 큐에 삽입하고 방문 처리를 한다.
		2. 큐에서 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 큐에 삽입하고 방문 처리
		3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복
 	 
	* BFS는 큐 자료구조에 기초한다는 점에서 큐 자료구조 이용, DFS보다 수행시간은 좋은 편
 	 
 	 
