# 깊이 우선 탐색(DFS, Depth-First-Search)
- 루트 노드에서 시작해 다음 분기(branch)로 넘어가기 전에 해당 분기
  를 완벽하게 탐색.

# 깊이 우선 탐색의 특징.
- 스택이나 재귀함수를 이용해서 구현
- 자기 자신을 호출하는 순환 알고리즘의 형태
- 전위 순회를 포함한 다른 형태의 트리 순회는 모두 DFS의 한 조율.
- 알고리즘을 구현할 때 가장 큰 차이점은 그래프 탐색의 경우 어떤
  노드를 방문했었는지 여부를 반드시 검사.
  미 검사 시 무한 루프에 빠질 위험이 있음.

# 깊이 우선 탐색의 과정.

