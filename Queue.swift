struct Queue<T> {
    //Queue<T> : 제네릭
    private var queue : [T] = []
    // private : 외부 접근 불가능, 정보은닉기법
    // var : 변경 가능한 변수, 변경 불가능하게 선언하고 싶을 경우 let
    // [T] : 제네릭 타입, 큐에 저장될 자료형을 구체적으로 정의하지 않음
    // = [] : 빈배열로 초기화
    // 스위프트는 배열이 동적으로 할당됨

    public var count: Int{
        return queue.count
    }
    // public : 외부 접근 가능 인터페이스
    // count 메소드를 int 타입으로 선언
    // queue의 요소를 전부 세서 return

    public var isEmpty : Bool{
        return queue.isEmpty
    }
    // isEmpty 메소드를 bool 타입으로 선언
    // queue의 요소가 비었을 경우 return
    public mutating func enqueue(_ element : T){
        queue.append(element)
    }
    // mutating : 구조체 내부의 멤버변수 참조 가능
    // func enqueue(element : T ) : 파라미터로 제네릭 타입의 자료형을 입력받음
    // append : element를 rear에 이어붙이는 메소드
    public mutating func dequeue() -> T?{
        return isEmpty ? nil : queue.removeFirst()
    }
    // func dequeue() -> T? : 큐가 비어있으면 nil 반환, 요소가 있으면 해당 요소를 반환
    // 삼항연산자, isEmpty 가 true일경우 nil 반환, false 일경우 front의 요소 삭제
    public var peek: T? {
        return queue.first
    }
    // front : T? : 반환되는 자료형에 옵셔널 적용, 값이 비어있을 경우 nil, 값이 존재할경우 해당 자료형 반환
    // 배열의 메소드 first를 통해 front의 요소 peek
    public func display() {
        if isEmpty {
            print("큐가 비어 있습니다.")
        } else {
            print("큐의 요소: \(queue)")
        }
    }
}
var intQueue = Queue<Int>()
//Queue 구조체를 int 형으로 선언, 객체명 intQueue
intQueue.enqueue(10)  
intQueue.enqueue(20) 
intQueue.enqueue(30)  

intQueue.display()
intQueue.dequeue()

print(intQueue.peek ?? "큐가 비어 있습니다.") 
intQueue.display()
