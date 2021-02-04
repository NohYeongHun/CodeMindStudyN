// import java.io.*;
// import java.util.*;

// public class Main {
// 	public static void main(String[] args) throws Exception{
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
// 		StringTokenizer st;

// 		int topIdx=-1;
// 		int[] stack;
// 		String command;

// 		stack = new int[Integer.parseInt(br.readLine())];

// 		for(int i=0; i<stack.length; i++){
// 			st = new StringTokenizer(br.readLine(), " ");
// 			command = st.nextToken();

// 			switch(command){
// 				case "push":
// 					stack[++topIdx] = Integer.parseInt(st.nextToken()); break;
// 				case "pop":
// 					if(topIdx != -1) bw.write(Integer.toString(stack[topIdx--]) + "\n");
// 					else bw.write("-1\n");
// 					break;
// 				case "size":
// 					bw.write(Integer.toString(topIdx+1) + "\n"); break;
// 				case "empty":
// 					if(topIdx != -1) bw.write("0\n");
// 					else bw.write("1\n");
// 					break;
// 				case "top":
// 					if(topIdx != -1) bw.write(Integer.toString(stack[topIdx]) + "\n");
// 					else bw.write("-1\n");
// 					break;
// 				default:
// 			}
// 		}

// 		bw.flush();
// 		br.close();
// 		bw.close();		
// 	}
// }
