# MATLAB -> C++ to solve Ax = b

Taking old MATLAB code for a project in Numerical Linear Algebra to use as C++ code.

### givens_ls.m
A linear solver using Givens transforms.

```{matlab}
function [ x, rnk ] = givens_ls( A,b )
%FUNCTION [X] = GIVENS_LS(A,b)
%find least squares solution

    [rows,columns] = size(A);
    [R,p,rnk] = givens_qr(A);
    
    for j = 1:columns        
       for k = 1+j:rows
            [c,s] = givens_decode(R(k,j));
     
            bj = b(j);
            bk = b(k);
            
            b(j) = c*bj + s*bk;
            b(k) = -s*bj + c*bk;
        end
    end
    
    b_top = b(1:rnk);
    first_nonzero = rnk;
    while abs(b_top(first_nonzero)) < eps && first_nonzero > 0,
        first_nonzero = first_nonzero -1;
    end
    
    %back substitution
    for k = first_nonzero:-1:1,
        b_top(k) = b_top(k) / R(k,k);
        if k ~= 1,
            b_top(1:k-1) = b_top(1:k-1) - b_top(k)*R(1:k-1,k);
        end
    end
    
    x = zeros(columns,1);
    x(1:rnk) = b_top;
    x(p(1:rnk)) = x(1:rnk);
end
```

```{cpp}
VectorXd GivensLinearSolver(MatrixXd Mat_A, VectorXd Vec_b) {
  MatrixXd Mat_R = GivensQR(Mat_A)
  
  for (int j = 0; j < Mat_A.cols(); j++) {
    for (int i = 0; i < Mat_A.rows(); i++) {
      Vector2d cs = GivensDecode(Mat_R(i,j));
      
      double bi = b(i);
      double bj = b(j);
      
      b(i) = cs(0) * bj + cs(1) * bj;
      b(j) = cs(0) * bj - cs(2) * bi;
    }
  }
  
  return Vec_x;
}
```

### givens_fullqr.m

```{matlab}
function [Q,R,p,rnk ] = givens_fullqr( A )
%UNTITLED15 Summary of this function goes here
%   Detailed explanation goes here
    [qr,p,rnk] = givens_qr(A);
    R = triu(qr);
    Q = givens_q(qr);
end
```

### givens_encode.m

```{matlab}
function  rho = givens_encode( c,s )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    if c == 0
        rho = 1;
    elseif abs(s) < abs(c)
        rho = sign(c) * s / 2;
    else
        rho = sign(s) * 2 / c;
    end
end
```

### givens_decode.m

```{matlab}
function [ c,s ] = givens_decode( rho )
%UNTITLED6 Summary of this function goes here
%   Detailed explanation goes here
    if rho == 1,
        c = 0; s = 1;
    elseif abs(rho) < 1,
        s = 2 * rho; c = sqrt(1 - s^2);
    else
        c = 2 / rho; s = sqrt(1-c^2);
    end
end
```

### givens_cs.m
```{matlab}
function [ c,s,sigma ] = givens_cs( x1,x2 )
%[C,S] = GIVENS_CS(x1,x2)

    if x1==0 && x2 == 0,
        c=1; s = 0; %sigma = 0;
    
    elseif x2 == 0,
        c = 1; s = 0; %sigma = 0;

    elseif abs(x2) > abs(x1),
        
        t= x1/x2; r = sqrt(1+t^2);
        s = (1/r); c = s*t; %sigma = x2*r;
    else
        t = x2/x1; r=sqrt(1+t^2);
        c = 1/r; s = c*t; %sigma = x1*r;
    end
end
```

### givens_matrix.m
```{matlab}
function [ G ] = givens_matrix( x1,x2,index1,index2,rows)
%UNTITLED8 Summary of this function goes here
%   Detailed explanation goes here
    c = x1/sqrt(x1^2 + x2^2);
    s = x2/sqrt(x1^2 + x2^2);
    G = eye(rows);
    
    G(index1,index1) = c;
    G(index2,index2) = c;
    G(index1,index2) = s;
    G(index2,index1) = -s;
end
```

### givens_qr.m

```{matlab}
function [ R,p,rnk ] = givens_qr( A )
%FUNCTION [R,P] = GIVENS_QR(A)
% Returns the QR factorization of A with a vector containign information
% about how QR has been permuted
%   Detailed explanation goes here    
    
    
    R = A;
    
    [rows,columns] = size(R);
    
    rnk = min(rows,columns);
    
    norm_eps = eps*norm(A,'fro');
    
    norm_vec = zeros(columns);
    column_order = 1:columns;
    
    for n = 1:columns
       norm_vec(n) = norm(R(:,n),2)^2;
    end
    
    for j = 1:rnk
       
        [m,m_ind] = max(norm_vec(j:columns));
        if m < norm_eps
            rnk = j-1;
            break;
        end

        m_ind = m_ind + j-1;
        if norm_vec(j) ~= m,           
            norm_vec([j,m_ind]) = norm_vec([m_ind,j]);            
            column_order([j,m_ind]) = column_order([m_ind,j]);            
            R(:,[j,m_ind]) = R(:,[m_ind,j]);    
        end
        
        for k = (j+1):rows
            [c,s] = givens_cs(R(j,j),R(k,j));
            rho = givens_encode(c,s);
            [c,s] = givens_decode(rho);
            rho = givens_encode(c,s);
            x1 = R(j,j:columns);
            x2 = R(k,j:columns);
            R(j,j:columns) = c*x1 + s*x2;
            R(k,j:columns) = -s*x1 + c*x2;            
            R(k,j) = rho;
        end
        
        norm_vec(j+1:columns) = norm_vec(j+1:columns) - R(j,j+1:columns).^2;
    end
    p = column_order;
    
end
```

### givens_q.m

```{matlab}
function [ Q ] = givens_q( R )
%UNTITLED13 Summary of this function goes here
%   Detailed explanation goes here
    [rows,columns] = size(R);    
    Q=eye(rows);
    for j = 1:columns
        for k = j+1:rows
            [c,s] = givens_decode(R(k,j));
            x1 = Q(1:rows,j);
            x2 = Q(1:rows,k);
            Q(1:rows,j) = c*x1 + s*x2;
            Q(1:rows,k) = -s*x1 + c*x2;
        end
    end
end
```
