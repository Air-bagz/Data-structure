//Dijkstra

final[5]	//标记各顶点是否已找到最短路径 

dist[5]		//最短路径长度 

path[5]		//路径上的前驱

//初始：若从v_0开始，令final[0]=true;	dist[0]=0;	path[0]=-1
//		其余顶点final[k]=false; dist[k]=arcs[0][k]; path[k]=(arcs[0][k]==\infty)?-1:0
//n-1轮处理：循环遍历所有顶点 ，找到还没确定最短路径，且dist最小的顶点V_i,令final[i]=true。
//			 并检查所有邻接自V_i的顶点V_j，若final[j]==false且dist[i]+arcs[i][j]<dist[j]，
//			 则令dist[j]=dist[i]+arcs[i][j]		path[j]=i
//	注:arcs[i][j]表示Vi到Vj的弧的权值 
