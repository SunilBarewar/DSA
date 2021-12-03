    public ListNode middleNode(ListNode head) {
         if(head == null || head.next == null){
            return head;
        }
        ListNode fast = head;
        ListNode slow = head;
        
        do {
            slow  = slow.next;
            fast = fast.next;
            if(fast.next != null)
                fast = fast.next;
        }while(fast != null && fast.next != null);
        
        return slow;
    }