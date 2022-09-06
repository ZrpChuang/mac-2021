n=10;
A = zeros(n,n);
for i=1:n
    A(i,i)=i;
    if i+1<=n
        A(i,i+1)=1/2;
        A(i+1,i)=1/2;
    end
    if i+2<=n
        A(i,i+2)=1/2;
        A(i+2,i)=1/2;
    end
end

b=ones(1,n);
result=zeros(1,n);

for k=1:15%迭代十五次
    for i=1:n%立面一共的元素个数
        before=0;
        for j=1:i-1
            before=before+A(i,j)*result(j);
        end%之前的元素
        after=0;
        for j=i+1:n
            after=after+A(i,j)*result(j);
        end%之后的元素    
        result(i)=-0.1*result(i)+1.1/A(i,i)*(b(i)-before-after);
    end
end






