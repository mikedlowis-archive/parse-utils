var NAVTREE =
[
  [ "Parse Utils", "index.html", [
    [ "Class List", "annotated.html", [
      [ "AST", "class_a_s_t.html", null ],
      [ "ASTPrinter", "class_a_s_t_printer.html", null ],
      [ "BTParser", "class_b_t_parser.html", null ],
      [ "Exception", "class_exception.html", null ],
      [ "ILexer", "class_i_lexer.html", null ],
      [ "IParser", "class_i_parser.html", null ],
      [ "IVisitor", "class_i_visitor.html", null ],
      [ "LLKParser", "class_l_l_k_parser.html", null ],
      [ "LLNLexer", "class_l_l_n_lexer.html", null ],
      [ "ScopeStack", "class_scope_stack.html", null ],
      [ "Symbol", "class_symbol.html", null ],
      [ "Token", "class_token.html", null ]
    ] ],
    [ "Class Index", "classes.html", null ],
    [ "Class Hierarchy", "hierarchy.html", [
      [ "AST", "class_a_s_t.html", null ],
      [ "Exception", "class_exception.html", null ],
      [ "ILexer", "class_i_lexer.html", [
        [ "LLNLexer", "class_l_l_n_lexer.html", null ]
      ] ],
      [ "IParser", "class_i_parser.html", [
        [ "BTParser", "class_b_t_parser.html", null ],
        [ "LLKParser", "class_l_l_k_parser.html", null ]
      ] ],
      [ "IVisitor", "class_i_visitor.html", [
        [ "ASTPrinter", "class_a_s_t_printer.html", null ]
      ] ],
      [ "ScopeStack", "class_scope_stack.html", null ],
      [ "Symbol", "class_symbol.html", null ],
      [ "Token", "class_token.html", null ]
    ] ],
    [ "Class Members", "functions.html", null ],
    [ "File List", "files.html", [
      [ "source/exception/exception.cpp", "exception_8cpp.html", null ],
      [ "source/exception/exception.d", "exception_8d.html", null ],
      [ "source/exception/exception.h", "exception_8h.html", null ],
      [ "source/lexer/ilexer.cpp", "ilexer_8cpp.html", null ],
      [ "source/lexer/ilexer.d", "ilexer_8d.html", null ],
      [ "source/lexer/ilexer.h", "ilexer_8h.html", null ],
      [ "source/lexer/llnlexer/llnlexer.cpp", "llnlexer_8cpp.html", null ],
      [ "source/lexer/llnlexer/llnlexer.d", "llnlexer_8d.html", null ],
      [ "source/lexer/llnlexer/llnlexer.h", "llnlexer_8h.html", null ],
      [ "source/lexer/token/token.cpp", "token_8cpp.html", null ],
      [ "source/lexer/token/token.d", "token_8d.html", null ],
      [ "source/lexer/token/token.h", "token_8h.html", null ],
      [ "source/parser/iparser.cpp", "iparser_8cpp.html", null ],
      [ "source/parser/iparser.d", "iparser_8d.html", null ],
      [ "source/parser/iparser.h", "iparser_8h.html", null ],
      [ "source/parser/ast/ast.cpp", "ast_8cpp.html", null ],
      [ "source/parser/ast/ast.d", "ast_8d.html", null ],
      [ "source/parser/ast/ast.h", "ast_8h.html", null ],
      [ "source/parser/btparser/btparser.cpp", "btparser_8cpp.html", null ],
      [ "source/parser/btparser/btparser.d", "btparser_8d.html", null ],
      [ "source/parser/btparser/btparser.h", "btparser_8h.html", null ],
      [ "source/parser/llkparser/llkparser.cpp", "llkparser_8cpp.html", null ],
      [ "source/parser/llkparser/llkparser.d", "llkparser_8d.html", null ],
      [ "source/parser/llkparser/llkparser.h", "llkparser_8h.html", null ],
      [ "source/symbol/scopestack.cpp", "scopestack_8cpp.html", null ],
      [ "source/symbol/scopestack.d", "scopestack_8d.html", null ],
      [ "source/symbol/scopestack.h", "scopestack_8h.html", null ],
      [ "source/symbol/symbol.cpp", "symbol_8cpp.html", null ],
      [ "source/symbol/symbol.d", "symbol_8d.html", null ],
      [ "source/symbol/symbol.h", "symbol_8h.html", null ],
      [ "source/visitor/ivisitor.cpp", "ivisitor_8cpp.html", null ],
      [ "source/visitor/ivisitor.d", "ivisitor_8d.html", null ],
      [ "source/visitor/ivisitor.h", "ivisitor_8h.html", null ],
      [ "source/visitor/astprinter/astprinter.cpp", "astprinter_8cpp.html", null ],
      [ "source/visitor/astprinter/astprinter.d", "astprinter_8d.html", null ],
      [ "source/visitor/astprinter/astprinter.h", "astprinter_8h.html", null ]
    ] ],
    [ "File Members", "globals.html", null ]
  ] ]
];

function createIndent(o,domNode,node,level)
{
  if (node.parentNode && node.parentNode.parentNode)
  {
    createIndent(o,domNode,node.parentNode,level+1);
  }
  var imgNode = document.createElement("img");
  if (level==0 && node.childrenData)
  {
    node.plus_img = imgNode;
    node.expandToggle = document.createElement("a");
    node.expandToggle.href = "javascript:void(0)";
    node.expandToggle.onclick = function() 
    {
      if (node.expanded) 
      {
        $(node.getChildrenUL()).slideUp("fast");
        if (node.isLast)
        {
          node.plus_img.src = node.relpath+"ftv2plastnode.png";
        }
        else
        {
          node.plus_img.src = node.relpath+"ftv2pnode.png";
        }
        node.expanded = false;
      } 
      else 
      {
        expandNode(o, node, false);
      }
    }
    node.expandToggle.appendChild(imgNode);
    domNode.appendChild(node.expandToggle);
  }
  else
  {
    domNode.appendChild(imgNode);
  }
  if (level==0)
  {
    if (node.isLast)
    {
      if (node.childrenData)
      {
        imgNode.src = node.relpath+"ftv2plastnode.png";
      }
      else
      {
        imgNode.src = node.relpath+"ftv2lastnode.png";
        domNode.appendChild(imgNode);
      }
    }
    else
    {
      if (node.childrenData)
      {
        imgNode.src = node.relpath+"ftv2pnode.png";
      }
      else
      {
        imgNode.src = node.relpath+"ftv2node.png";
        domNode.appendChild(imgNode);
      }
    }
  }
  else
  {
    if (node.isLast)
    {
      imgNode.src = node.relpath+"ftv2blank.png";
    }
    else
    {
      imgNode.src = node.relpath+"ftv2vertline.png";
    }
  }
  imgNode.border = "0";
}

function newNode(o, po, text, link, childrenData, lastNode)
{
  var node = new Object();
  node.children = Array();
  node.childrenData = childrenData;
  node.depth = po.depth + 1;
  node.relpath = po.relpath;
  node.isLast = lastNode;

  node.li = document.createElement("li");
  po.getChildrenUL().appendChild(node.li);
  node.parentNode = po;

  node.itemDiv = document.createElement("div");
  node.itemDiv.className = "item";

  node.labelSpan = document.createElement("span");
  node.labelSpan.className = "label";

  createIndent(o,node.itemDiv,node,0);
  node.itemDiv.appendChild(node.labelSpan);
  node.li.appendChild(node.itemDiv);

  var a = document.createElement("a");
  node.labelSpan.appendChild(a);
  node.label = document.createTextNode(text);
  a.appendChild(node.label);
  if (link) 
  {
    a.href = node.relpath+link;
  } 
  else 
  {
    if (childrenData != null) 
    {
      a.className = "nolink";
      a.href = "javascript:void(0)";
      a.onclick = node.expandToggle.onclick;
      node.expanded = false;
    }
  }

  node.childrenUL = null;
  node.getChildrenUL = function() 
  {
    if (!node.childrenUL) 
    {
      node.childrenUL = document.createElement("ul");
      node.childrenUL.className = "children_ul";
      node.childrenUL.style.display = "none";
      node.li.appendChild(node.childrenUL);
    }
    return node.childrenUL;
  };

  return node;
}

function showRoot()
{
  var headerHeight = $("#top").height();
  var footerHeight = $("#nav-path").height();
  var windowHeight = $(window).height() - headerHeight - footerHeight;
  navtree.scrollTo('#selected',0,{offset:-windowHeight/2});
}

function expandNode(o, node, imm)
{
  if (node.childrenData && !node.expanded) 
  {
    if (!node.childrenVisited) 
    {
      getNode(o, node);
    }
    if (imm)
    {
      $(node.getChildrenUL()).show();
    } 
    else 
    {
      $(node.getChildrenUL()).slideDown("fast",showRoot);
    }
    if (node.isLast)
    {
      node.plus_img.src = node.relpath+"ftv2mlastnode.png";
    }
    else
    {
      node.plus_img.src = node.relpath+"ftv2mnode.png";
    }
    node.expanded = true;
  }
}

function getNode(o, po)
{
  po.childrenVisited = true;
  var l = po.childrenData.length-1;
  for (var i in po.childrenData) 
  {
    var nodeData = po.childrenData[i];
    po.children[i] = newNode(o, po, nodeData[0], nodeData[1], nodeData[2],
        i==l);
  }
}

function findNavTreePage(url, data)
{
  var nodes = data;
  var result = null;
  for (var i in nodes) 
  {
    var d = nodes[i];
    if (d[1] == url) 
    {
      return new Array(i);
    }
    else if (d[2] != null) // array of children
    {
      result = findNavTreePage(url, d[2]);
      if (result != null) 
      {
        return (new Array(i).concat(result));
      }
    }
  }
  return null;
}

function initNavTree(toroot,relpath)
{
  var o = new Object();
  o.toroot = toroot;
  o.node = new Object();
  o.node.li = document.getElementById("nav-tree-contents");
  o.node.childrenData = NAVTREE;
  o.node.children = new Array();
  o.node.childrenUL = document.createElement("ul");
  o.node.getChildrenUL = function() { return o.node.childrenUL; };
  o.node.li.appendChild(o.node.childrenUL);
  o.node.depth = 0;
  o.node.relpath = relpath;

  getNode(o, o.node);

  o.breadcrumbs = findNavTreePage(toroot, NAVTREE);
  if (o.breadcrumbs == null)
  {
    o.breadcrumbs = findNavTreePage("index.html",NAVTREE);
  }
  if (o.breadcrumbs != null && o.breadcrumbs.length>0)
  {
    var p = o.node;
    for (var i in o.breadcrumbs) 
    {
      var j = o.breadcrumbs[i];
      p = p.children[j];
      expandNode(o,p,true);
    }
    p.itemDiv.className = p.itemDiv.className + " selected";
    p.itemDiv.id = "selected";
    $(window).load(showRoot);
  }
}

