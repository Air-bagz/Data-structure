//Floyd�㷨���Ĵ���
//......׼������������ͼ����Ϣ��ʼ������A��path
A[i][j]=arcs[i][j];
path[i][j]=-1;

for (int k=0; k<n; k++)	//������Vk��Ϊ��ת�� 
	for (int i=0; i<n; i++)	//������������iΪ�кţ�jΪ�к� 
		for (int j=0; j<n; j++)
			if A[i][j]>A[i][k]+A[k][j]		//��VkΪ��ת���·������ 
			{
				A[i][j]=A[i][k]+A[k][j];	//�������·������ 
				path[i][j]=k;			//��ת�� 
			}