class Solution {
    public long smallestNumber(long num) {
        if(num>0){
            String s= String.valueOf(num);
            char[] c = s.toCharArray();
            Arrays.sort(c);
            int i=0;
            while(c[i]=='0'){
                i++;
            }
            char temp=c[0];
            c[0]=c[i];
            c[i]=temp;
            StringBuilder sb= new StringBuilder();
            for(char c1:c){
                sb.append(c1);
            }
            return Long.parseLong(sb.toString());
        }else{
            String s= String.valueOf(num);
            s=s.replace("-","");
            char[] c = s.toCharArray();
            Arrays.sort(c);
            StringBuilder sb= new StringBuilder();
            for(char c1:c){
                sb.append(c1);
            }
            return (-1)*Long.parseLong(sb.reverse().toString());

        }
    }
}