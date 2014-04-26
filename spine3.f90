program spine
    real :: h(4),l(4),u(4),f(5),d(5),A(5,5)
    integer :: IPIV(5),INFO
    f = (/0.5,0.5477,0.6245,0.6708,0.728/)
    h = (/0.05,0.09,0.06,0.08/)
    l(1)=0.0
    u(4)=0.0
    A(:,:)=0
    do i=2,4
        l(i) = h(i)/(h(i)+h(i-1))
        u(i-1) = h(i-1)/(h(i)+h(i-1))
    end do
    
    do i=1,5
        if (i .eq. 1) then
            d(i) = 0
        else if(i .eq. 5) then
            d(i) = 0
        else
            d(i) = 6*((f(i+1)-f(i))/h(i)-(f(i)-f(i-1))/h(i-1))/(h(i-1)+h(i))
        end if
    end do

    !A(1,4) = u(1)
    !A(4,1) = l(4)

    do j=1,5
        A(j,j) = 2.0
        do i=1,4
            if (i .eq. j) then
               A(j,i+1) = l(i)
               A(j+1,i) = u(i)
            end if
        end do
    end do

    print *,A(1,:)
    print *,A(2,:)
    print *,A(3,:)
    print *,A(4,:)
    print *,A(5,:)
    print *,d
    CALL SGESV(5,1,A,5,IPIV,d,5,INFO)
    print *,l

    print *,u

    print *,d
    
end program 
