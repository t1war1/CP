package rough;

public class SortLLX {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Node<Integer> head=new Node<>(10);
		head.next=new Node<>(40);
		head.next.next=new Node<>(53);
		head.next.next.next=new Node<>(30);
		head.next.next.next.next=new Node<>(67);
		head.next.next.next.next.next=new Node<>(12);
		head.next.next.next.next.next.next=new Node<>(89);
		head=sort(head);
		System.out.println();
		print(head);
	}
	
	public static Node<Integer> sort(Node<Integer> head) {
	      
		Node<Integer> list1=null,list2=null,tail1=null,tail2=null;
      	int j=0;
      	while(head!=null)
        {
          if(j%2==0)
          {
            if(list1==null)
            {
              list1=head;
              tail1=head;
            }
            else{
              tail1.next=head;
              tail1=tail1.next;
            }
          }
          else
          {
            if(list2==null)
            {
              list2=head;
              tail2=head;
            }else{
              tail2.next=head;
              tail2=tail2.next;
            }
          }
          head=head.next;j++;
        }
      tail1.next=null;tail2.next=null;
      
      print(list1);
      System.out.println();
      list2=reverse(list2);
      print(list2);
      
      return merge(list1,list2);
	}
  
	
	public static <T>void print(Node<T> head)
	{
		Node<T> temp=head;
		while(temp!=null)
		{
			System.out.print(temp.data+"->");
			temp=temp.next;
		}
	}
	
  public static Node<Integer> merge(Node<Integer> list1,Node<Integer> list2)
  {
    Node<Integer> ans=null,tail=null;
    
    if(list1.data.compareTo(list2.data)<=0)
    {
      ans=list1;tail=list1;
      list1=list1.next;
    }
    
    while(list1!=null && list2!=null)
    {
        if(list1.data.compareTo(list2.data)<=0)
   		 {
      		tail.next=list1;
          tail=tail.next;
          list1=list1.next;
   		 }
      	else{
          tail.next=list2;
          tail=tail.next;
          list2=list2.next;
        }
    }
    if(list1!=null)
    {
    		tail.next=list1;
    }
    if(list2!=null)
    {
    		tail.next=list2;
    }
    return ans;
  }
  public static <T>Node<T> reverse(Node<T> head)
  {
	  if(head==null || head.next==null)
		{
			return head;
		}
		Node<T> finalhead=reverse(head.next);
		head.next.next=head;
		head.next=null;
		return finalhead;
  }
}
class Node<T> {
	public T data;
	public Node<T> next;

	public Node(T data) {
		this.data = data;
		this.next = null;
	}
}	

