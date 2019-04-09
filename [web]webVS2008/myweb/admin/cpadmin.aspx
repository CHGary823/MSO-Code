<%@ Page language="c#" Codebehind="cpadmin.aspx.cs" AutoEventWireup="false" Inherits="web.admin.cpadmin" %>
<%@ Register TagPrefix="uc1" TagName="cpmenu" Src="../control/cpmenu.ascx" %>
<%@ Register TagPrefix="uc1" TagName="cptop" Src="../control/cptop.ascx" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>admincp</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<SCRIPT language="JavaScript" src="Common/JavaScript/Menu.js"></SCRIPT>
		<LINK href="Common/CSS/Default.CSS" type="text/css" rel="stylesheet">
		<LINK href="Common/CSS/menuStyleXP.CSS" type="text/css" rel="stylesheet">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<uc1:cptop id="Cptop1" runat="server"></uc1:cptop>
			<table id="Table1" cellSpacing="1" cellPadding="3" width="780" border="0">
				<tr>
					<td vAlign="top" width="207" rowSpan="2">
						<table cellSpacing="0" cellPadding="0" width="100%" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table cellSpacing="1" cellPadding="10" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" height="498"><uc1:cpmenu id="Cpmenu1" runat="server"></uc1:cpmenu></td>
										</tr>
										<tr bgColor="#f9f9f9">
											<td height="80">
												<div align="center">
													<p><font color="#ff6633"><A href="../logout.aspx" target="_blank"></font><b><font color="#ff6666">�]�N�˳�</font></b></A></p>
												</div>
												</FONT></FONT></td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
					<td vAlign="top" width="556">
						<table id="Table2" cellSpacing="0" cellPadding="0" width="563" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td vAlign="top">
									<table id="Table3" cellSpacing="1" cellPadding="8" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" align="left">
												<TABLE id="Table4" style="WIDTH: 560px" cellSpacing="1" cellPadding="1" width="560" border="0">
													<TR>
														<TD style="WIDTH: 107px; HEIGHT: 22px" colSpan="2"><b>����T�б�</b></TD>
													</TR>
													<TR>
														<TD style="HEIGHT: 122px" vAlign="top" colSpan="2"><asp:datagrid id="DataGrid1" runat="server" AutoGenerateColumns="False" Width="542px" PageSize="5">
																<Columns>
																	<asp:BoundColumn DataField="id" HeaderText="id"></asp:BoundColumn>
																	<asp:BoundColumn DataField="userid" HeaderText="��̖"></asp:BoundColumn>
																	<asp:BoundColumn DataField="name" HeaderText="�ǷQ"></asp:BoundColumn>
																	<asp:BoundColumn DataField="lastlogintime" HeaderText="�����ꑕr�g"></asp:BoundColumn>
																	<asp:BoundColumn DataField="lastloginip" HeaderText="������IP"></asp:BoundColumn>
																	<asp:BoundColumn DataField="state" HeaderText="�Ƿ���"></asp:BoundColumn>
																	<asp:ButtonColumn Text="&lt;div id=&quot;de&quot; onclick=&quot;JavaScript:return confirm('�_���h����?')&quot;&gt;�h��&lt;/div&gt;"
																		HeaderText="����" CommandName="Delete"></asp:ButtonColumn>
																	<asp:ButtonColumn Text="�x��" ButtonType="PushButton" CommandName="Select"></asp:ButtonColumn>
																</Columns>
																<PagerStyle Mode="NumericPages"></PagerStyle>
															</asp:datagrid></TD>
													</TR>
													<TR>
														<TD style="HEIGHT: 30px" align="left" colSpan="2">
															<hr>
														</TD>
													</TR>
													<TR>
														<TD style="WIDTH: 131px" align="left"><B>����T����</B></TD>
														<TD align="left"><FONT face="����">
																<asp:Label id="lblid" runat="server"></asp:Label></FONT></TD>
													</TR>
													<TR align="left">
														<TD style="WIDTH: 131px" align="left">��̖</TD>
														<TD align="left"><asp:textbox id="tbuserid" runat="server" Width="152px" Columns="20"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 131px; HEIGHT: 22px" align="left">�ܴa</TD>
														<TD style="HEIGHT: 22px" align="left"><asp:textbox id="tbpassword" runat="server" Width="152px" Columns="30" TextMode="Password"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 131px" align="left">�ǷQ(�@ʾ�������ط�)</TD>
														<TD align="left"><asp:textbox id="tbname" runat="server" Width="152px" Columns="4"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 131px" align="left">��B</TD>
														<TD align="left"><asp:dropdownlist id="ddstate" runat="server">
																<asp:ListItem Value="1" Selected="True">����</asp:ListItem>
																<asp:ListItem Value="0">ͣ��</asp:ListItem>
															</asp:dropdownlist></TD>
													</TR>
													<TR>
														<TD align="center" colSpan="2"><asp:button id="btnedit" runat="server" Visible="False" Text="�� �� �� �� �T"></asp:button><asp:button id="btnadd" runat="server" Text="�� �� �� �� �T"></asp:button></TD>
													</TR>
												</TABLE>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
				</tr>
			</table>
		</form>
	</body>
</HTML>
