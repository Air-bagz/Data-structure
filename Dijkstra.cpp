//Dijkstra

final[5]	//��Ǹ������Ƿ����ҵ����·�� 

dist[5]		//���·������ 

path[5]		//·���ϵ�ǰ��

//��ʼ������v_0��ʼ����final[0]=true;	dist[0]=0;	path[0]=-1
//		���ඥ��final[k]=false; dist[k]=arcs[0][k]; path[k]=(arcs[0][k]==\infty)?-1:0
//n-1�ִ���ѭ���������ж��� ���ҵ���ûȷ�����·������dist��С�Ķ���V_i,��final[i]=true��
//			 ����������ڽ���V_i�Ķ���V_j����final[j]==false��dist[i]+arcs[i][j]<dist[j]��
//			 ����dist[j]=dist[i]+arcs[i][j]		path[j]=i
//	ע:arcs[i][j]��ʾVi��Vj�Ļ���Ȩֵ 
